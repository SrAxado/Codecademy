#ifndef SCHOOL_HPP
#define SCHOOL_HPP
#include "Teacher.hpp"
#include "Student.hpp"
#include "Subject.hpp"
#include <string>
#include <vector>

using namespace std;

class School {
// class School: public Teacher, public Student {  // converting School into an interface??
private:
  string name;
  // the following vectors will be act as reference for the entire system
  vector<Person*> people;
  // for an easier and faster indexing
  vector<int> teachersIdx;
  vector<int> studentsIdx;
  // vector<Teacher*> teachers;
  // vector<Student*> students;
  vector<Subject*> subjects;
  // Teacher* configTeacher(string const name, Subject* const subject, int const yearsOfExperience);
  // Student* configStudent(string const name, Subject* const subject);
  
  public:
  School(string schoolName);
  ~School();
  
  // methods related to subjects: add, get, remove and display information
  void configSubject(Subject* subject);
  Subject* configSubject(string const subjectName, int const level);
  Subject* findSubject(string const subjectName, int const level) const;
  void removeSubject(Subject* subject);
  void removeSubject(string const subjectName, int const level);
  void removePersonSubject(string const name, string const subjectName, int const level); // removes a subject form a person
  void displaySubjects() const;
  
  int findPersonIdx(string const name) const;
  Person* findPerson(string const name) const;
  // adds a new person (Teacher/Student) to the school people's list or configures an existant one
  void configPerson(Person* person);
  Student* configPerson(string const name, int const gradeLevel = 0);
  Person* configPerson(string const name, string const subjectName, int const level, int const yearsOfExperience = 0);
  void configPerson(Person* const person, Subject* const subject, int const yearsOfExperience = 0);
  // void displayPerson() const;
  
  void displayTeachers() const;
  
  void displayStudents() const;
  
  Teacher* getTeacher(Person* person) const;
  Student* getStudent(Person* person) const;

  void configRating(Person* const teacher, Person* const student, Subject* const subject, int const rate, string const feedback = "");
  void configRating(Person* const teacher, Person* const student, Subject* const subject, string const comment);

};

#endif