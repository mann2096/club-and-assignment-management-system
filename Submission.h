#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student;
class Assignment;

class Submission{
  private:
  Student* submittedBy;
  Assignment* assignment;
  int score;
  string file;
  bool late;

  public:
  Submission(Student* student1, Assignment* assignment1, int score1=0, string file1="", string timeOfSubmission="");
  Student* getStudent();
  Assignment* getAssignment();
  int getScore();
  string getFile();
  bool isLate();
  void setScore(int score);
};
