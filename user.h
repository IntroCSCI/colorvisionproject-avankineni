#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;

class user
{
  private:
    string name;
    int age;
    double rating;

public:
  void setName(string);
  string getName();
  void setAge(int);
  int getAge();
  void setRating(double);
  double getRating();
};

#endif