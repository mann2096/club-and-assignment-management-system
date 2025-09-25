#include"member.h"
using namespace std;

Member::Member(Student* s,Club* c,string r):student(s),club(c),role(r){}
Student* Member::getStudent()const{return student;}
Club* Member::getClub()const{return club;}
string Member::getRole()const{return role;}
void Member::display()const{
  cout<<"Student: "<<student->getName()<<" (Role: "<<role<<")"<<endl;
}
void Member::setRole(const string& newRole){role=newRole;}

Admin::Admin(Student* s,Club* c):Member(s,c,"Admin"){}
void Admin::createAssignment(const string& title,int maxScore,const string& deadline){
  Assignment* a=new Assignment(title,maxScore,deadline);
  club->addAssignment(a);
  cout<<"Assignment '"<<title<<"' created in club "<<club->getClubName()<<endl;
}
void Admin::addMember(Student* s){
  club->addMember(s);
  cout<<"Student added to club: "<<club->getClubName()<<endl;
}
void Admin::removeMember(int studentID){
  club->removeMember(studentID);
  cout<<"Student removed from club: "<<club->getClubName()<<endl;
}
void Admin::promoteToChecker(Member* m){
  m->setRole("AssignmentChecker");
  cout<<"Promoted "<<m->getStudent()->getName()<<" to AssignmentChecker."<<endl;
}
void Admin::demoteToNormal(Member* m){
  m->setRole("Normal");
  cout<<"Demoted "<<m->getStudent()->getName()<<" to Normal member."<<endl;
}
void Admin::changeAdmin(Member* newAdmin){
  if(newAdmin->getClub()!=club){
    cout<<"Error: Member does not belong to this club."<<endl;
    return;
  }
  this->setRole("Normal");
  newAdmin->setRole("Admin");
  cout<<"Admin changed to "<<newAdmin->getStudent()->getName()<<endl;
}

AssignmentChecker::AssignmentChecker(Student* s,Club* c):Member(s,c,"AssignmentChecker"){}
void AssignmentChecker::gradeAssignment(Assignment* a,Student* s,int score){
  cout<<"Grading assignment '"<<a->getTitle()<<"' for student "<<s->getName()<<" with score "<<score<<endl;
}

NormalMember::NormalMember(Student* s,Club* c):Member(s,c,"Normal"){}
