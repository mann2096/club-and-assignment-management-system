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
  void addMember(Student* s);
  void removeMember(int studentID);
  void promoteToChecker(Member* m);
  void demoteToNormal(Member* m);
  void changeAdmin(Member* newAdmin);
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
<<<<<<< HEAD


=======
>>>>>>> 3a7fcb9f6c772ee50cc7533b32e4897b9db2a929
