#pragma once
#include<iostream>
#include<string>
#include"Vector.h"
#include"member.h"
#include"Assignment.h"
#include"Submission.h"
#include"student.h"
using namespace std;
#include <vector>
class Member;
class Assignment;
class Student;
class Submission;

class Club{
  private:
  string clubName;
  int clubID;
  Vector<Member*> members;
  Vector<Assignment*> assignments;
  Admin* admin;
  Vector<AssignmentChecker*> assignmentCheckers;
  friend class Admin;

  public:
  Club(string name,int id,Student* adminStudent);
  string getClubName()const;
  Admin* getAdmin()const;
  void getMembers()const;
  bool isAdmin(Student* s)const;
  bool isAssignmentChecker(Student* s)const;
  void viewAssignments(Student* student)const;

  Vector<Member*> getAssignmentCheckers()const;
  void joinClubNoCheck(Student* s);
  void removeMember(int studentID);
  void addAssignment(Assignment* a);
};
