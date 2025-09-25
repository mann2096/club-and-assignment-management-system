#include<iostream>
#include <string>
#include "club.h"
#include "Vector.h"
#include "Assignment.h"
#include "student.h"
#include "member.h"
#include "Submission.h"
using namespace std;

Vector<Student*> Students;
Vector<Club*> Clubs;

Student* login(){
  int ID; string password;
  cout<<"Enter ID: ";
  cin>>ID;
  cout<<"Enter password: ";
  cin>>password;
  
  for(int i=0; i<Students.size(); i++){
    if((*(Students[i])).getID()==ID && (*(Students[i])).checkPassword()==password){
      cout<<"Successful login"<<endl;
      return Students[i];
    }
  }
  cout<<"Incorrect ID or password"<<endl;
  return nullptr;
}

Student* FirstMenu(){
  cout<<"1. New Student"<<endl;
  cout<<"2. Login"<<endl;
  int num; cin>>num;
  if(num==1){
    int ID, string name, string password;
    cout<<"Enter your ID"<<endl;
    cin>>ID;
    cout<<"Enter your name"<<endl;
    cin>>name;
    cout<<"Enter your password"<<endl;
    cin>>password;
    Student* s=new Student(ID, name, password);
    Students.push_back(s);
    Student* s2=login();
    return s2;
  }else if(num==2){
    Students* s2=login();
    return s2;
  }else{
    cout<<"Invalid input"<<endl;
    return nullptr;
  }
}

void mainMenu(Student* student){
  while(true){
    cout<<"MAIN MENU"<<endl;
    cout<<"1. Join a club"<<endl;
    cout<<"2. View your clubs"<<endl;
    cout<<"3. Exit"<<endl;
    
    int choice; cin>>choice;

    switch(choice){
      case 1:

      case 2:
      (*student).viewMyClubs(student);
      
    }

  }
}

int main(){
  cout<<"CLUB AND ASSIGNMENT MANAGAMENT SYSTEM"<<endl;
  Student* student=nullptr;
  while(student==nullptr){
    student=FirstMenu();
  }
  mainMenu(student);

  return 0;
}