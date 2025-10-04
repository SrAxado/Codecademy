#include <iostream>
#include "School.hpp"

using namespace std;

int main() {
  School mySchool("Greenwood High");
  
  mySchool.configPerson("Alice Johnson", "English", 3, 2);
  mySchool.configPerson("Alice Johnson", "Mathematics", 3, 5);
  mySchool.configPerson("Alice Johnson", "Mathematics", 3, 7);
  mySchool.configPerson("Alice Johnson", "Mathematics", 5, 2);
  mySchool.configPerson("Alice Johnson", "Science", 3, 3);

  mySchool.configPerson("Bob Smith", "Science", 5, 2);


  // we can remove subjects manually from a Teacher manually, making use of the Teacher's method
  Person* alice = mySchool.findPerson("Alice Johnson");
  Teacher* teacherAlice = mySchool.getTeacher(alice);
  // if (teacherAlice != nullptr) {
  //   cout << "---> verified that she's a teacher" << endl;
  // } else {
  //   cout << "She should be a teacher" << endl;
  // }
  teacherAlice->removeSubject(mySchool.findSubject("Mathematics", 3));
  // or using a chain of methods
  mySchool.findPerson("Alice Johnson")->removeSubject(mySchool.findSubject("English", 3));
  // teacherAlice->displayInfo();

  mySchool.displaySubjects();
  mySchool.displayTeachers();


  mySchool.configPerson("José Febras", 3);
  mySchool.configPerson("António dos Bifes", "English", 3);
  mySchool.configPerson("António dos Bifes", "Mathematics", 3);
  mySchool.configPerson("António dos Bifes", "Science", 5);
  // we can remove subject manually making use of the Student object's method
  mySchool.removePersonSubject("António dos Bifes", "English", 3);
  // mySchool.configPerson("António dos Bifes", "Science", 5)->removeSubject(mySchool.findSubject("English", 3));

  // or using a chain of methods
  mySchool.findPerson("António dos Bifes")->removeSubject(mySchool.findSubject("English", 3));
  // mySchool.removeSubjectStudent("António dos Bifes", 3, "English");
  // mySchool.configStudent("António dos Bifes", 3)->removeSubject(mySchool.findSubject("English", 4));

  mySchool.displayStudents();

  Person* jose = mySchool.findPerson("José Febras");
  Student* studentJose = mySchool.getStudent(jose);
  // if (studentJose != nullptr) {
  //   cout << "---> verified that he's a student" << endl;
  // } else {
  //   cout << "He should be a student" << endl;
  // }
  
  // non-predefined subject definition with enrollment restricted by grade level
  studentJose->configSubject(mySchool.configSubject("Português", 2));

  // we can rate a teacher on his/her subject through the school object
  Subject* mathematics = mySchool.findSubject("Mathematics", 5);
  mySchool.configRating(alice, jose, mathematics, 8, "Gosto mais das raízes cúbicas do que das quadradas!");
  mySchool.configRating(alice, jose, mathematics, "És um tony!!");
  // teacherAlice->configRating(jose, mySchool.findSubject("Mathematics", 5), 8, "Gosto mais das raízes cúbicas do que das quadradas!");
  // teacherAlice->configRating(jose, mySchool.findSubject("Mathematics", 5), NULL, NULL, "És um tony!!");
  
  // or using the teacher object approach
  teacherAlice->configRating(studentJose, mathematics, 7, "I really enjoyed your class.");
  teacherAlice->configRating(studentJose, mathematics, "Thank you very much!");
  // teacherAlice->addRating(4, "I really enjoyed your class", "Thank you very much!");
  
  mathematics = mySchool.findSubject("Mathematics", 3);
  teacherAlice->configRating(studentJose, mathematics, 5, "I imagine that this can't get any better");

  Subject* science = mySchool.findSubject("Science", 3);
  mySchool.configPerson(jose, science);
  teacherAlice->configRating(studentJose, science, 4, "I really enjoyed this subject... even thought, I barely understood anything.");


  Person* antonio = mySchool.findPerson("António dos Bifes");
  Student* studentAntonio = mySchool.getStudent(antonio);
  teacherAlice->configRating(studentAntonio, science, 5, "I imagine that this can't get any better");
  teacherAlice->configRating(studentAntonio, science, "You're too sweet!");
  // teacherAlice->addRating(5, "I imagine that this can't get any better", "You're too sweet!");

  
  mySchool.configRating(mySchool.findPerson("Bob Smith"), mySchool.findPerson("António dos Bifes"),
    mySchool.findSubject("Science", 5), 6, "If cold fusion was so hot as you presented it, I would be an iceberg!");
  mySchool.configRating(mySchool.findPerson("Bob Smith"), mySchool.findPerson("António dos Bifes"), 
  mySchool.findSubject("Science", 5), "I'm sure you would be a rock in a polar bear's whiskey glass.");

  teacherAlice->printRatings();
  // mySchool.findTeacher("Alice Johnson")->printRatings();
  mySchool.getTeacher(mySchool.findPerson("Bob Smith"))->printRatings();


  return 0;
}