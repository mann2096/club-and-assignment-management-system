#include<iostream>
#include<string>
#include"Vector.h"
#include"Member.h"
#include"Assignment.h"
#include"Student.h"
using namespace std;

class Member;
class Assignment;
class Student;

class Club{
  private:
  string clubName;
  int clubID;
  Vector<Member*> members;
  Vector<Assignment*> assignments;

  public:
  Club(string name,int id,Student* adminStudent);
  string getClubName()const;
  Member* getAdmin()const;
  void getMembers()const;
  void viewAssignments()const;
  vector<Member*> getAssignmentCheckers()const;
  void joinClubNoCheck(Student* s);
};
