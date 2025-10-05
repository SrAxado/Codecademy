#include "Teacher.hpp"


// Teacher::Teacher(string const teacherName, Subject* const subject) 
//   : Person(teacherName, subject) {}

Teacher::Teacher(string const teacherName, Subject* const subject, int const yearsOfExperience)
  : Person(teacherName) {
    cout << "Creating teacher " << teacherName << "..." << endl;
    configSubject(subject, yearsOfExperience);
}

Teacher::~Teacher() {
  cout << "Clearing " << this->getName() << "'s data... ";
  subjectExperience.erase(subjectExperience.begin(), subjectExperience.end());
  // cout << "--> subjectExperience cleared successfully" << endl;

  for (auto it = ratings.begin(); it != ratings.end();) {
    // cout << "Clearing " << it->second[0]->getRating() << endl;
    it->second.clear(); // deletes the rating vector
    // cout << "Clearing the subject rating" << endl;
    ratings.erase(it++);  // deletes current rating and increases the iterator to the next rating
  }
  // cout << "Everyting cleared from Teacher" << endl;
  ratings.erase(ratings.begin(), ratings.end());
}

// configures a subject to be taught by the teacher and/or the number of years of experience doing it
void Teacher::configSubject(Subject* const subject, int const years) {
  if (subjectExperience[subject]) {
    if (subjectExperience[subject] == years) {
      cout << this->getName() << "'s association with the " << subject->getSubjectName() << " is already made." << endl;
      return;
    } else {
      cout << "Changing the years of experience to " << years << endl;
      // subjectExperience[subject] = years;  // updates the years of experience
    }
  } else {
    cout << "Adding " << subject->getSubjectName() << " [" << subject->getGradeLevel() << "] subject with " 
      << years << " years of experience to " << this->getName() << endl;
    // subjectExperience[subject] = years;  // adds the subject with its years of experience
  }
  subjectExperience[subject] = years;
}


// finds the enrolled subject by object
Subject* Teacher::findSubject(Subject* const subject) const {
  for (auto& subjectTmp : subjectExperience) {
    if (subjectTmp.first->checkSubject(subject)) {
      return subjectTmp.first;
    }
  }
  return nullptr;
}

// finds the enrolled subject by name and gradeLevel
Subject* Teacher::findSubject(string const subjectName, int const gradeLevel) const {
  for (auto& subject : subjectExperience) {
    if (subject.first->checkSubject(subjectName, gradeLevel)) {
      return subject.first;
    }
  }
  return nullptr;
}

int Teacher::getYearsOfExperience(Subject* const subject) {
  return subjectExperience[subject];
}

// removes a subject from the teacher's list of taught subjects
void Teacher::removeSubject(Subject* const subject) {
  map<Subject*, int>::iterator it = subjectExperience.find(subject);

  if (it == subjectExperience.end()) {
    cout << this->getName() << " doesn't teach " << subject->getSubjectName() << " [" << subject->getGradeLevel() << "]" << endl;
  
  } else {
    cout << this->getName() << " will no longer teach " << subject->getSubjectName() << " [" << subject->getGradeLevel() << "]" << endl;
    subjectExperience.erase(it);
  }
}

// prints the teacher's information (name, number of subjects taught along with the list of all subjects with their years of experience)
void Teacher::displayInfo() const {
  cout << " => Teacher " << this->getName() << " [" << subjectExperience.size() << " subjects] ==" << endl;
  // for (auto const& [subject, yearsExp] : yearsOfExperience) { // C++ 17
    // cout << "  -- " << subject->getSubjectName() << " [" << subject->getGradeLevel() << "]" 
    //   << " --> " << yearsExp << " years of experience" << endl;
  for (auto const& subject : subjectExperience) {
    cout << "   -- " << subject.first->getSubjectName() << " [" << subject.first->getGradeLevel() << "]"
      << " --> " << subject.second << " years of experience" << endl;
  // map<Subject*, int>::iterator it;
  // for (it = yearsOfExperience.begin(); it != yearsOfExperience.end(); ++it) {
  //   cout << " -- " << it->first->getSubjectName() << " [" << it->first->getGradeLevel() << "]"
  //     << " --> " << it->second << " years of experience" << endl;
  }
  cout << endl;
}

// finds the subject's rating created by a specific student
Rating* Teacher::findStudentSubjectRating(Student* const student, Subject* const subject) {
  // verifies if the subject is taught by the current teacher and if it already exists a rating to the specific subject
  if ((subjectExperience[subject] > 0) && (ratings[subject].size() > 0)) {

    vector<Rating*> subjectRating = ratings[subject];
    // for (auto const& rating : ratings[subject]) {
    for (auto const& rating : subjectRating) {
      if (rating->checkStudentCreator(student)) {
        return rating;
      }
    }
  }
  return nullptr;
}

// adds or changes a new or existing rate for a subject that is taught by the teacher
void Teacher::configRating(Student* const student, Subject* const subject, int const rate, string const feedback) {
  if (subjectExperience[subject]) { // checks if the teacher teaches such subject to allow a feedback about it
    
    Rating* rating = findStudentSubjectRating(student, subject);
    if (!rating) { // if there isn't a rating for the specified subject by the specified student, adds one rating
      cout << "Adding rating from " << student->getName() << " to " << this->getName()
        << " for " << subject->getSubjectInfo() << endl;
      // cout << "---- " << subject << endl;
      ratings[subject].push_back(new Rating(student, rate, feedback));
    
    } else {  // it already exists a rating fot the specified subject by the specified student

      if (rating->getRating() != rate) {  // edits the rate of the specified subject by the specified student
        rating->setRating(rate);
      }
      if (rating->getFeedback() != feedback) {  // edits the feedback of the specifid subject by the specified student
        rating->setFeedback(feedback);
      }
    }

  } else {
    cout << this->getName() << " does not teach " << subject->getSubjectInfo() << endl;
  }
}

// will add a comment to an already existant rate/feedback
void Teacher::configRating(Student* const student, Subject* const subject, string const comment) {
  Rating* rating = findStudentSubjectRating(student, subject);
  if (!rating) {
    cout << subject->getSubjectInfo() << " doesn't have any rating/feedback yet. Add one before comment on it." << endl;
  } else {
    rating->setComment(comment);
  }
}

// using the subjects enrolled list, prints the subject's ratings
void Teacher::printRatings(int num) {

  if (ratings.size()) { // there's one or more ratings available
    cout << " ============================== " << this->getName() << "'s Ratings ==============================" << endl;

    for (auto it = subjectExperience.begin(); it != subjectExperience.end(); ++it) {  // scrolls the list of subjects taught
      cout << "   ==== " << it->first->getSubjectInfo() << " -- " << getAvgRating(it->first) << " avg. rating" << endl;

      for (auto rating : ratings[it->first]) {
        rating->printRating();
        if (--num == 0) {
          break;
        }
      }
      
      // vector<Rating*> subjectRating = ratings[it->first]; // gets the list of ratings related to a subject
      // if (subjectRating.size()) {
      //   // title list: subject name (average rating)
      //   cout << "  == " << it->first->getSubjectInfo() << " -- " << to_string(getAvgRating(it->first)) << endl;
      //   if (--num == 0) {
      //     break;
      //   }
  
        // for (auto rating : subjectRating) {
        //   rating->printRating();
        // }
      }
      cout << " =============================================================================" << endl;
    }
    // for (auto const& [subject, years] : subjectExperience) {
    // for (auto const& subjectExp = subjectExperience.begin(); subjectExp != subjectExperience.end(); ++ subjectExp) {
    // for (auto const& subjectExp : subjectExperience) {
    // auto it = yearsOfExperience.begin();
    // for (auto it = ratings.begin(); it != ratings.end(); ++it) {
    //     cout << "-- " << (it->first)->getSubjectInfo() << " --" << endl;
    //     // cout << " [" << to_string((ratings[subjectExp.first])->getRating()) << "] " << ratings[subjectExp.first]->getFeedback() << endl;
    //     cout << " => " << it->second->getRatingCreator()->getName() << ": " << it->second->getFeedback() << endl;
    //     cout << endl;
    // }
  }



// void Teacher::setRating(Subject* subject, int const rate) {
//   ratings[subject] = new Rating();
// }

double Teacher::getAvgRating(Subject* subject) {
  double ratingAvg = 0;
  int numRatings = ratings[subject].size();

  if (numRatings > 0) {
    for (auto const rating : ratings[subject]) {
      ratingAvg += rating->getRating();
    }
    
    ratingAvg /= numRatings;
  }

  return ratingAvg;
}

// Rating* Teacher::getSubjectRating(Subject* subject) {
//   if (ratings[subject].size() > 0) {
//     for (auto const rating : ratings[subject]) {
//       if (rating->)
//     }
//   }
// }
