#include "Rating.hpp"

Rating::Rating(Student* const student, int const rate, string const feedbck)
  : rating(rate), feedback(feedbck), ratingCreator(student) {}
  // : ratingCreator(student), rating(rate), feedback(feedbck) {}


void Rating::setComment(string const commnt) { comment = commnt; }

void Rating::setRating(int const rate) { rating = rate; };

void Rating::setFeedback(string const feedbck) { feedback = feedbck; }

void Rating::setRatingCreator(Student* const student) { ratingCreator = student; }


bool Rating::checkStudentCreator(Student* const student) const {
  return (student == this->ratingCreator) ? true : false;
}


int Rating::getRating() const { return rating; };

string Rating::getComment() const { return comment; };

string Rating::getFeedback() const { return feedback; };

Student* Rating::getRatingCreator() const { return ratingCreator; }


void Rating::printRating() const {
  cout << "     ==> " << this->getRatingCreator()->getName() << "'s rate is: " << this->getRating() << endl;
  if (feedback != "") {
    cout << "       -- " << feedback << endl;
  }

  if (comment != "") {
    cout << "       -->> " << comment << endl;
  }
}