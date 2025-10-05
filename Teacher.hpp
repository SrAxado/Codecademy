#ifndef TEACHER_HPP
#define TEACHER_HPP
#include "Person.hpp"
#include "Subject.hpp"
#include "Rating.hpp"
#include <map>
#include <vector>
// #include <string>

using namespace std;

class Teacher: public Person {
  private:
    map<Subject*, int> subjectExperience; // list of taught years of experience per subject
    map<Subject*, vector<Rating*>> ratings; // list of ratings per subject

  public:
    // using Person::Person;  // to allow Teacher("Name") object construction
    Teacher(string const teacherName, Subject* const subject, int const yearsOrExperience);
    // Teacher(string const teacherName, Subject* const subject);
    ~Teacher();
    // string findSubject() const { return subject; };
    // virtual bool checkValidSubject(const string subject) = 0;
    // string getName() const;
    // void setName(const string name);
    void configSubject(Subject* const subject, int const yearsOfExperience = 0) override;
    // void configSubject(const string subjectName, const int yearsOfExperience);
    Subject* findSubject(Subject* const subject) const override;
    Subject* findSubject(string const subjectName, int const gradeLevel) const override;
    int getYearsOfExperience(Subject* const subject);
    
    void removeSubject(Subject* const subject) override;
    
    void displayInfo() const override;
    // void displaySubjects() const;

    // 
    Rating* findStudentSubjectRating(Student* const student, Subject* const subject);
    void configRating(Student* const student, Subject* const subject, int const rate, string const feedback = "");
    void configRating(Student* const student, Subject* const subject, string const comment);
    void printRatings(int num = 10);
    double getAvgRating(Subject* subject);
    // Rating* getSubjectRating(Subject* subject);
};


#endif