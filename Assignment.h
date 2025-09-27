#pragma once
#include<iostream>
#include "Vector.h"
using namespace std;

class Student;
class Club;
class Submission;

class Assignment{
  private:

  Club* parentClub;
  string Title;
  int scoreMax;
  string Deadline;
  Vector<Submission*> submissions;

  public:

  Assignment(string title, int scoreMax, string deadline, Club* parent);

  void viewSubmissions();

  void viewYourSubmissions(Student* s);
  
  void addSubmission(Submission* sub);

  string getTitle();

  Club* getParentClub();

  string getDeadline();

  int getScoreMax();
};