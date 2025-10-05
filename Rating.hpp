#ifndef RATING_HPP
#define RATING_HPP
#include "Student.hpp"
#include <iostream>

using namespace std;

class Rating {
  protected:

    int rating;
    string feedback;  // probably produced by a student/student's parent
    string comment;  // probably as an answer by the teacher/school
    Student* ratingCreator; // creator of the rating or feedback

  public:
    // Rating(Student* const student, int const rate, string const feedbck = "", string const commnt = "")
    //   : ratingCreator(student), rating(rate), feedback(feedbck), comment(commnt) {}
    
    // we first create a rating and only after we'll allow adding a comment to it
    Rating(Student* const student, int const rate, string const feedbck = "");
    void setComment(string const commnt);
    void setRating(int const rate);
    void setFeedback(string const feedbck);
    void setRatingCreator(Student* const student);

    bool checkStudentCreator(Student* const student) const;
    
    int getRating() const;
    string getComment() const;
    string getFeedback() const;
    Student* getRatingCreator() const;

    void printRating() const;
};

#endif