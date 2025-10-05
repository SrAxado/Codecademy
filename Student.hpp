#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "Person.hpp"
#include "Subject.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Student: public Person {
  private:
    int gradeLevel;
    vector<Subject*> enrolledSubjects;

  public:
    // we can't allow Student("Name") object construction because we need the gradeLevel defined
    // using Person::Person;
    // Student(string const name);
    Student(string const name, int const gradeLevel);
    Student(string const name, Subject* const subject);
    ~Student();
    void changeGradeLevel(int const level);
    int getGradeLevel() const;
    bool checkGradeLevel(int const level) const;
    // void setName(string const name);
    // string getName() const;
    void configSubject(Subject* const subject, int const gradeLevel = 0) override;  // we will discard the gradeLevel information
    // void configSubject(string const subjectName, int const gradeLevel);

    Subject* findSubject(Subject* const subject) const override;
    Subject* findSubject(std::string const subjectName, int const yearsOfExperience) const override;

    void removeSubject(Subject* const subject) override;
    bool checkEnrolled(Subject* const subject) const;
    // void enrollInSubject(Subject* const subject);
    
    void displayInfo() const override;
    void displayEnrolledSubject() const;
};

#endif