#ifndef PERSON_HPP
#define PERSON_HPP
#include "Subject.hpp"
#include <iostream>
#include <vector>

class Person {
  private:
    std::string name;

  protected:
    /// list of subjects of the teacher or student
    // vector<Subject*> associatedSubjects;

  public:
    Person(const std::string name) : name(name) {};
    // Person(std::string const name, Subject* const subject);
    virtual ~Person() { cout << "[" << name << "]"<< endl; };
    // std::string getName() const;
    std::string getName() const { return this->name; };
    // void setName(const std::string name);
    void changeName(std::string const name) { this->name = name;};

    virtual void configSubject(Subject* const subject, int const years) = 0;
    // virtual void configSubject(const std::string subjectName, const int yearOrLevel) = 0;
    // void configSubject(Subject* const subject);
    // void configSubject(std::string const subjectName, int const yearOrLevel);
    
    virtual Subject* findSubject(Subject* const subject) const = 0;
    virtual Subject* findSubject(std::string const subjectName, int const gradeLevel) const = 0;
    // virtual Subject* findSubject(const std::string subjectName) const = 0;
    
    virtual void removeSubject(Subject* const subject) = 0;
    // virtual void displaySubjects() const = 0;
    virtual void displayInfo() const = 0;
};

#endif