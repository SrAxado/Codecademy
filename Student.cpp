#include "Student.hpp"

// Student::Student(string const name) : Person(name), gradeLevel(0) {}

Student::Student(string const name, int const gradeLevel)
  : Person(name), gradeLevel(gradeLevel)  {}

Student::Student(string const name, Subject* const subject) 
  : Student(name, subject->getGradeLevel()) {
    cout << "Creating student " << name << "..." << endl;
    configSubject(subject);
}

Student::~Student() {
  cout << "Deleting student... ";
  // enrolledSubjects.resize(0);
  enrolledSubjects.clear();
}

void Student::changeGradeLevel(int const level) { gradeLevel = level; }

int Student::getGradeLevel() const { return gradeLevel; }

bool Student::checkGradeLevel(int const level) const {
  return (this->gradeLevel == level);
}

/// enrolls the student in a subject
// we will discard the passed gradeLevel value, as it's already defined in the subject object
void Student::configSubject(Subject* const subject, int const gradeLevel) {
  // checks if the new subject is appropriate to the level of the student
  if (checkGradeLevel(subject->getGradeLevel())) {
    // checks if the student is already enrolled
    if (!checkEnrolled(subject)) {
      // adds subject to the enrolled list vector
      cout << "Enrolling " << this->getName() << " in " 
        << subject->getSubjectName() << " [" << subject->getGradeLevel() << "]" << endl;
      enrolledSubjects.emplace_back(subject);
    } else {
      cout << this->getName() << " is  already enrolled in " << subject->getSubjectName() 
        << " [" << to_string(gradeLevel) << "]" << endl;
    }
  } else {
    cout << "The " << subject->getSubjectName() << " is not the suited level for " << this->getName() << endl;
  }
}

// finds the enrolled subject by object
Subject* Student::findSubject(Subject* const subject) const {
  for (auto& subjectTmp : enrolledSubjects) {
    if (subjectTmp->checkSubject(subject)) {
      return subjectTmp;
    }
  }
  return nullptr;
}

// finds the enrolled subject by name and gradeLevel
Subject* Student::findSubject(string const subjectName, int const gradeLevel) const {
  for (auto& subject : enrolledSubjects) {
    if (subject->checkSubject(subjectName, gradeLevel)) {
      return subject;
    }
  }
  return nullptr;
}

void Student::removeSubject(Subject* const subject) {
  for (vector<Subject*>::iterator itSubject = enrolledSubjects.begin(); itSubject != enrolledSubjects.end(); ++itSubject) {
    // finds the enrolled subject and deletes it from the list
    if (subject->checkSubject((*itSubject)->getSubjectName(),(*itSubject)->getGradeLevel())) {
      cout << "Unenrolling " << this->getName() << " from " << subject->getSubjectInfo() << endl;
      enrolledSubjects.erase(itSubject);
      return;
    }
  }
  cout << this->getName() << " is not enrolled in " << subject->getSubjectInfo() << endl;
}

bool Student::checkEnrolled(Subject* const subject) const {
  for (auto& subjectTmp : enrolledSubjects) {
    if (subjectTmp->checkSubject(subject)) {
      cout << this->getName() << " is already enrolled in " << subject->getSubjectName() << endl;
      return true;
    }
  }
  return false;
}

// prints the list of all the subjects the student is enrolled in
void Student::displayEnrolledSubject() const {
  if (enrolledSubjects.size() > 0) {
    cout << getName() << " is enrolled in:" << endl;
    for (auto& subject : enrolledSubjects) {
      cout << subject->getSubjectName() << endl;
    }
    cout << endl;
  }
}

// prints the student's information (name, grade level and the list of enrolled subjects)
void Student::displayInfo() const {
  cout << " == Student " << this->getName() << " -- " << this->gradeLevel << " grade level ==" << endl;
  
  for (auto const& subject : enrolledSubjects) {
    cout << "   -- " << subject->getSubjectName() << " [" << subject->getGradeLevel() << "]" << endl;
  }
  cout << endl;
}