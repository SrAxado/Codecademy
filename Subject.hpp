#ifndef SUBJECT_HPP
#define SUBJECT_HPP
// #include "Student.hpp"
// #include "Rating.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Subject {
  // private:
    // vector<Rating*> ratings;

  protected:
    string subjectName;
    int gradeLevel; // subject's grade level

  public:
    Subject(const string subject, const int level);
    ~Subject();
    // string findSubject() override;
    // void changeSubjectName(const string subjectName);  // invalid use of 'this' outside of a non-static member function
    string getSubjectName() const;
    bool checkSubject(string const subjectName, int const gradeLevel) const;
    bool checkSubject(Subject* const subject) const;
    void setGradeLevel(int const years);
    int getGradeLevel() const;
    void displayInformation() const;
    string getSubjectInfo() const;
};

class Math: public Subject {
  public:
    using Subject::Subject;  // for a possible Math("Mathematics", xx) construction
    Math(const int gradeLevel);
};

class Science: public Subject {
  public:
    using Subject::Subject;  // for a possible Science("Science", xx) construction
    Science(const int gradeLevel);
};

class English: public Subject {
  public:
    using Subject::Subject;  // for a possible English("English", xx) construction
    English(const int gradeLevel);
};

#endif