#include "user.h"
#include <string>

using std::string;

void user::setName(string nameInput)
{
  name = nameInput;
}
string user::getName()
{
  return name;
}
void user::setAge(int ageInput)
{
  age = ageInput;
}
int user::getAge()
{
  return age;
}
void user::setRating(double ratingInput)
{
  rating = ratingInput;
}
double user::getRating()
{
  return rating;
}
