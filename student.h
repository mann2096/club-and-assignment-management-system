#include<iostream>
#include<string>
#include"Vector.h"
#include"Assignment.h"
#include"Submission.h"
using namespace std;

class Club;

class Student{
  private:
  string name;
  int id;
  string password;
  Vector<Club*> joinedClubs;
  Vector<Submission*> submissions;

  public:
  Student(int id,string name,string password);
  int getID()const;
  string getName()const;
  bool checkPassword(int enteredID,string enteredPassword);
  void joinClubs(Club* c);
  void viewMyClubs();
  void submitAssignment(Assignment* a,string file,string timeOfSubmission);
  void viewSubmissions()const;
};
