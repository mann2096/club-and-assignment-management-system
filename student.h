#pragma once
#include<iostream>
#include<string>
#include"Vector.h"

using namespace std;
class Club;
class Assignment;
class Submission;

class Student{
  private:
  string name;
  int id;
  string password;
  Vector<Club*> joinedClubs;

  public:
  Student(int id,string name,string password);
  int getID()const;
  string getName()const;
  bool checkPassword(int enteredID,string enteredPassword);
  void joinClubs(Club* c);

  void viewMyClubs(Student* student);
  void submitAssignment(Assignment* a,string file,string timeOfSubmission);
};
