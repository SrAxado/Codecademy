#include "Subject.hpp"

Subject::Subject(const string subject, const int level)
  : subjectName(subject), gradeLevel(level) {}

Subject::~Subject() {}

// void changeSubjectName(const string subject) {
//   this->subjectName = subject;
// }

string Subject::getSubjectName() const { return this->subjectName; }

bool Subject::checkSubject(string const subjectName, int const gradeLevel) const {
  if (this->subjectName == subjectName && this->gradeLevel == gradeLevel) {
    return true;
  } else {
    return false;
  }
}

bool Subject::checkSubject(Subject* const subject) const {
  if (this->subjectName == subject->getSubjectName() && this->gradeLevel == subject->getGradeLevel()) {
    return true;
  } else {
    return false;
  }
}

int Subject::getGradeLevel() const { return this->gradeLevel; }

void Subject::setGradeLevel(int const years) { this->gradeLevel = years; }


void Subject::displayInformation() const {
  cout << "     -- " << subjectName << " [" << gradeLevel << "]" << endl;
}

string Subject::getSubjectInfo() const {
  return subjectName + " [" + to_string(gradeLevel) + "]";
}


Math::Math(const int gradeLevel) : Subject::Subject("Mathematics", gradeLevel) {
  cout << "Adding Mathematics [" << gradeLevel << "] to the subjects list..." << endl;
};

Science::Science(const int gradeLevel) : Subject::Subject("Science", gradeLevel) {
  cout << "Adding Science [" << gradeLevel << "] to the subjects list..." << endl;
};

English::English(const int gradeLevel) : Subject::Subject("English", gradeLevel) {
  cout << "Adding English [" << gradeLevel << "] to the subjects list..." << endl;
};