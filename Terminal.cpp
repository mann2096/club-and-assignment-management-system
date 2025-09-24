#include<iostream>
#include <string>
#include "club.cpp"
#include "Vector.cpp"
#include "Assignment.cpp"
#include "Student.cpp"
#include "member.cpp"
#include "Submission.cpp"
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

void mainMenu(Student* student){
  while(true){
    cout<<"MAIN MENU"<<endl;
    cout<<"1. Join a club"<<endl;
    cout<<"2. View your clubs"<<endl;
    cout<<"3. View all clubs and members"<<endl;
    cout<<"3. Exit"<<endl;
    
    int choice; cin>>choice;

    switch(choice){
      case 1:
      for(int i=0; i<Clubs.size(); i++){
        cout<<(i+1)<<": "<<(*(Clubs[i]).clubName())<<endl;
      }
      while(true){
        cout<<"Enter the number of the club you wish to join: ";
        int num; cin>>num;
        if(num>=Clubs.size()){
          cout<<"Invalid input"<<endl;
          continue;
        }
        (*(Clubs[num])).joinClubNoCheck(student);
      }

    }
  }
}

int main(){
  cout<<"CLUB AND ASSIGNMENT MANAGAMENT SYSTEM"<<endl;
  Student* student=nullptr;
  while(student==nullptr){
    student=login();
  }
  mainMenu(student);

  return 0;
}