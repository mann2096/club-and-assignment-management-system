#include <iostream>
#include<string>
#include"student.h"
#include"Assignment.h"
using namespace std;

class Student;
class Assignment;

class Submission{
  private:
  Student* submittedBy;
  Assignment* assignment;
  int score;
  string file;
  bool isLate;

  public:
  Submission(Student* student1,Assignment* assignment1,int score1,string file1,string timeOfSubmission);
  Student* getStudent();
  Assignment* getAssignment();
  int getScore();
  string getFile();
  bool isLate();
};
