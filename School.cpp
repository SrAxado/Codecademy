#include "School.hpp"

School::School(string schoolName) : name(schoolName) {}

School::~School() {
  cout << "  _________________________ Cleaning _________________________ " << endl;
  cout << "         ----------------    People    ----------------" << endl;
  for (auto& person : people) {
    // cout << "Deleting " << person->getName() << endl;
    delete person;
  }

  cout << "        ----------------    Subjects    ----------------" << endl;
  for (auto& subject : subjects) {
    cout << "Deleting " << subject->getSubjectName() << " [" << subject->getGradeLevel() << "]" << endl;
    delete subject;
  }
  cout << " ______________________________________________________________" << endl;
}

// inserts subject object to the list of subjects
void School::configSubject(Subject* subject) {
  subjects.push_back(subject);
}

// checks if the subject already exists, adding it to the list of subjects if not and returning it
Subject* School::configSubject(string const subjectName, int const num) {
  Subject* subject = findSubject(subjectName, num);
  
  if (!subject) { // subject inexistant; creating one
    // cout << "Subject not existant!!" << endl;
    if (subjectName == "Mathematics") {
      subject = new Math(num);
    } else if (subjectName == "Science") {
      subject = new Science(num);
    } else if (subjectName == "English") {
      subject = new English(num);
    } else {
      cout << "Non pre-defined subject will be created" << endl;
      subject = new Subject(subjectName, num);
    }
    cout << "Adding " << subjectName << " [" << num << "] to the subjects list" << endl;
    subjects.push_back(subject);

  }
  // else {}  // the subject already exists; it will only return it
  return subject;
}

// finds the subject from the general list of all subjects taught in the school, returning it or a nullptr
Subject* School::findSubject(string const subjectName, int const num) const {
  for (auto& subject : subjects) {
    if (subject->checkSubject(subjectName, num)) {
      return subject;
    }
  }
  return nullptr;
}

void School::removeSubject(Subject* subject) {
  // erase(subjects, subject);  // it will only work when compiled with C++20 or later
  // vector<Subject*>::iterator it = find(subjects.begin(), subjects.end(), subject);
  // subjects.erase(it);
  // remove(subjects, subject);
  for (auto it = subjects.begin(); it != subjects.end(); ++it) {
    if (*it == subject) {
      cout << "Removing ";
      subject->displayInformation();
      subjects.erase(it);
    }
  }
}

void School::removeSubject(string const subjectName, int const level) {
  removeSubject(findSubject(subjectName, level));
}

// remove a subject from a person
void School::removePersonSubject(string const name, string const subjectName, int const level) {
  Person* person = findPerson(name);
  Subject* subject = findSubject(subjectName, level);
  person->removeSubject(subject);
}

void School::displaySubjects() const {
  cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
  cout << "   --> [" << subjects.size() << "] Existant subjects in " << name << ": <--" << endl;
  for (auto& subject : subjects) {
    subject->displayInformation();
  }
  cout << endl;
  cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}


// there can't exist two people with the same name in the people's list
int School::findPersonIdx(string const name) const {
  int peopleListSize = people.size();
  for (auto idx = 0; idx < peopleListSize; ++idx) {
    if (people[idx]->getName() == name) {
      return idx;
    }
  }
  return -1;
}

// finds a specific person and returns a pointer to him/her or a nullptr if he/she doesn't exist
Person* School::findPerson(string const name) const {
  int idx = findPersonIdx(name);
  return (idx >= 0) ? people[idx] : nullptr;
}

// checks for which type of person is and adds it to the list of people and respective index list
void School::configPerson(Person* person) {
  // checks if the person already exists in the school people's list
  if (findPersonIdx(person->getName()) >= 0) {
    cout << person->getName() << " already exists." << endl;
    return;
  }

  // by upcasting person, will determine which type of person it is and adding it to the system
  Teacher* teacher = dynamic_cast<Teacher*>(person);
  if (teacher != nullptr) { // it's a teacher, adds it to the teachersIdx list
    cout << "Adding teacher ";
    if (people.size()) {
      teachersIdx.push_back(people.size()); // adds the index of the person to be inserted in the people's list
    } else {  // if the vector is empty
      teachersIdx.push_back(0);  // adds the first index element of the people's list to teachersIdx list
    }
  } else {  // it's a student, adds it to the studentsIdx list
    if (people.size()) {
      studentsIdx.push_back(people.size()); // adds the index of the person to be inserted in the people's list
    } else {
      studentsIdx.push_back(0); // adds the first index element of the people's list to the studentIdx list
    }
  }
  // inserts the teacher or student to the school's list of people
  people.push_back(person);
  cout << person->getName() << endl;
}

// we will consider that we're dealing with a student if there isn't years of experience involved with a specific subject's level
Student* School::configPerson(string const name, int const gradeLevel) {
  Person* person = findPerson(name);
  if (person) {
    // check if the Person* is a student and verify if it is enrolled in the passed in year
    Student* student = dynamic_cast<Student*>(person);  // we could consider that we're dealing with a student, static casting Student
    if (student != nullptr) {
      if (student->getGradeLevel() == gradeLevel) {
        cout << student->getName() << " is already enrolled in the " << student->getGradeLevel() << "th grade level" << endl;
      } else {
        /// if we're allowing to change the grade level of a student, we should also do a clean up of the subjects he's enrolled in
        /// Let's assume that the student can have subjects from different grade levels (a university student usually does)
        cout << "Changing " << student->getName() << "'s grade level to " << gradeLevel<< endl;
        student->changeGradeLevel(gradeLevel);
      }
      return student;

    } else {
      cout << "You can't assign a grade level to a teacher" << endl;  // there are only two types of people
      return nullptr;
    }
  } else {
    Student* student = new Student(name, gradeLevel);
    studentsIdx.push_back(people.size());
    people.push_back(student);
    cout << "Adding student " << name << " to the " << gradeLevel << "th grade level" << endl;

    return student;
  }
}

// we will consider that we're dealing with a teacher if there is a yearsOfExperience value passed in
// or a student if there isn't any value passed in
Person* School::configPerson(string const name, string const subjectName, int const level, int const yearsOfExperience) {
  // creates a new subject if no such subject exists or gets a pointer to it if it exists
  Subject* subjectPtr = configSubject(subjectName, level);

  // creates a new teacher if he doesn't exist or gets a pointer to him if it does
  Person* personPtr = findPerson(name);
  // if (personPtr) {
  if (yearsOfExperience > 0) {  // we'll assume it to be a Teacher
    if (personPtr) {  // the person already exists in the school list
      Teacher* teacher = dynamic_cast<Teacher*>(personPtr);
      if (teacher != nullptr) { // configures the existing teacher
        
        // verifies if the subject is already associated with the teacher
        // Subject* subjectTmp = teacher->findSubject(subjectPtr);
        int onSubjectExperience = teacher->getYearsOfExperience(subjectPtr);
        if (onSubjectExperience > 0) { // the subject is already associated with the teacher
          cout << "Teacher " << name << " is already associated to the " << subjectName << " subject. ";
          if (onSubjectExperience != yearsOfExperience) {
            cout << "Updating..." << endl;
            // teacher->configSubject(subjectPtr, yearsOfExperience); // configSubject will update the years of experience
          } else {
            return teacher;  // the years of experience won't need to be changed
          }
        }
        // } else {  // if the subject isn't associated with the teacher, makes the association
        //   teacher->configSubject(subjectPtr, yearsOfExperience); // configSubject will add the subject and its years of experience
        // }
        teacher->configSubject(subjectPtr, yearsOfExperience);  // configSubject will update or add the subject and its years of experience
        return teacher;
        
      } else {
        cout << "You can't assign years of experience to a student." << endl;
        return nullptr;
      }

    } else {  // creates a new teacher, and adds it to the list of people and its index to the list of teacher's list indexes
      Teacher* teacher = new Teacher(name, subjectPtr, yearsOfExperience);
      teachersIdx.push_back(people.size()); //
      people.push_back(teacher);
      return teacher;
    }

  } else if (yearsOfExperience == 0) { // we'll assume it to be a Student
    if (personPtr) {  // the person already exists in the school list
      Student* student = configPerson(name, level);
      if (student != nullptr) { // configures an existing student

        // verifies if the student is already enrolled in the subject
        Subject* subjectTmp = student->findSubject(subjectPtr);
        if(subjectTmp) {  // already enrolled
          cout << name << " is already enrolled in " << subjectName << " [" << level << "]" << endl;

        } else { // enrolling student in the subject
          student->configSubject(subjectPtr);
        }
        return student;

      } else {
        cout << "You can't assign a subject to a teacher having zero years of experience. "
          << "The first year of teaching counts as 1 year of experience." << endl;
        return nullptr;
      }
    } else {  // creates a new student, and adds it to the list of people and its index to the list of student's indexes
      Student* student = new Student(name, subjectPtr);
      studentsIdx.push_back(people.size());
      people.push_back(student);
      return student;
    }

  } else {
    cout << "Invalid number of years of experience." << endl;
    return nullptr;
  }

  return nullptr;
}

// adds a subject to a person (Teacher/Student)
void School::configPerson(Person* const person, Subject* const subject, int const yearsOfExperience) { // adds a subject to a student
  Teacher* teacher = getTeacher(person);
  if (teacher != nullptr) {
    teacher->configSubject(subject, yearsOfExperience);
  } else {
    getStudent(person)->configSubject(subject);
  }
}

// get the teacher by upcasting the person or nullptr if not
Teacher* School::getTeacher(Person* person) const {
  Teacher* teacher = dynamic_cast<Teacher*>(person);
  return teacher;
}
// get the student by upcasting the person or nullptr if not
Student* School::getStudent(Person* person) const {
  Student* student = dynamic_cast<Student*>(person);
  return student;
}

// displays the list of all teachers in the school
void School::displayTeachers() const {
  cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
  cout << "      ====== Teachers in " << name << ":  =======" << endl;
  for (auto& idx : teachersIdx) {
    // // cout << "Name: " << teacher->getName() << ", Subject: " << teacher->findSubject() << "\n";
    if (getTeacher(people[idx])) {
      cout << "  [ check ] ";
    } else {
      cout << "  [ X ] ";
    }
    people[idx]->displayInfo();
  }
  cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

// displays the list of all students in the school
void School::displayStudents() const {
  cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
  cout << "      ====== Students in " << name << ":  =======" << endl;
  for (auto& idx : studentsIdx) {
    // cout << "  - " << student->getName() << endl;
    if (getStudent(people[idx])) {
      cout << "  [ check ] ";
    } else {
      cout << "  [ X ] ";
    }
    people[idx]->displayInfo();
  }
  cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

// adds a feedback by a student to a teacher/subject
void School::configRating(Person* const pTeacher, Person* const pStudent, Subject* const subject, 
  int const rate, string const feedback) {
  Teacher* teacher = dynamic_cast<Teacher*>(pTeacher);
  Student* student = dynamic_cast<Student*>(pStudent);

  if ((teacher != nullptr) && (student != nullptr)) {
    teacher->configRating(student, subject, rate, feedback);
    
  } else {
    cout << "Something's not right!" << endl;
  }
}

// adds a comment to a feedback by a teacher
void School::configRating(Person* const pTeacher, Person* const pStudent, Subject* const subject, string const comment) {
  Teacher* teacher = static_cast<Teacher*>(pTeacher);
  Student* student = static_cast<Student*>(pStudent);

  teacher->configRating(student, subject, comment);
}