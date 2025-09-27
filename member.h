#pragma once
#include<iostream>
#include<string>
#include"student.h"
#include"club.h"
#include"Assignment.h"
using namespace std;

class Club;
class Student;
class Assignment;

class Member{
  protected:
  Student* student;
  Club* club;
  string role;

  public:
  Member(Student* s,Club* c,string r);
  virtual ~Member() {}
  Student* getStudent()const;
  Club* getClub()const;
  string getRole()const;
  void display()const;

  private:
  void setRole(const string& newRole);
  friend class Admin;
};

class Admin:public Member{
  public:
  Admin(Student* s,Club* c);
  void createAssignment(const string& title,int maxScore,const string& deadline);
  void addMember(int studentID);
  void removeMember(int studentID);
  void promoteToChecker(int studentID);
  void demoteToNormal(int studentID);
  void changeAdmin(int studentID);
};

class AssignmentChecker:public Member{
  public:
  AssignmentChecker(Student* s,Club* c);
  void gradeAssignment(Assignment* a,Student* s,int score);
};

class NormalMember:public Member{
  public:
  NormalMember(Student* s,Club* c);
};








