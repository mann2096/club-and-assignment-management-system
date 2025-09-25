#include"student.h"
#include"club.h"
#include<iostream>
using namespace std;

Student::Student(int id,string name,string password):id(id),name(name),password(password){}

int Student::getID()const{return id;}
string Student::getName()const{return name;}

bool Student::checkPassword(int enteredID,string enteredPassword){
  return(enteredID==id&&enteredPassword==password);
}

void Student::joinClubs(Club* c){
  if(c!=nullptr){
    joinedClubs.push_back(c);
    c->addMember(this);
  }
}

void Student::viewMyClubs(Student* student){
  cout<<"Clubs for "<<name<<" (ID: "<<id<<"):"<<endl;
  for(int i=0;i<joinedClubs.size();i++){
    cout<<(i+1)<<": "<<joinedClubs[i]->getClubName()<<endl;
  }
  cout<<endl<<"Enter the Club number, Enter 0 to exit"<<endl;
  int num; cin>>num;
  if(num==0) return;
  joinedClubs[i-1].viewAssignments(student);
  if()
}

void Student::submitAssignment(Assignment* a,string file,string timeOfSubmission){
  Submission* s=new Submission(this,a,file,timeOfSubmission);
  submissions.push_back(s);
  a->addSubmission(s);
}

void Student::viewSubmissions()const{
  cout<<"Submissions for "<<name<<" (ID: "<<id<<"):"<<endl;
  for(int i=0;i<submissions.size();i++){
    Submission* s=submissions[i];
    if(s){
      cout<<"- Assignment: "<<s->getAssignment()->getTitle()
          <<" | File: "<<s->getFile()
          <<" | Score: "<<s->getScore()
          <<(s->isLate()?" | Late":" | On time")<<endl;
    }
  }
}
