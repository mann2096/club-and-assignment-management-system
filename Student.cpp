#include"student.h"
#include "Submission.h"
#include "Assignment.h"
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

    c->joinClubNoCheck(this);
  }
}
Club* Student::viewMyClubs(Student* student){
  cout<<"Clubs for "<<name<<" (ID: "<<id<<"):"<<endl;
  for(int i=0;i<joinedClubs.size();i++){
    cout<<(i+1)<<": "<<joinedClubs[i]->getClubName()<<endl;
  }
  cout<<endl<<"Enter the Club number"<<endl;
  int num; cin>>num;
  return joinedClubs[num-1];
}

void Student::submitAssignment(Assignment* a,string file,string timeOfSubmission){
  Submission* s=new Submission(this,a,0,file,timeOfSubmission);
  submissions.push_back(s);
  a->addSubmission(s);
}