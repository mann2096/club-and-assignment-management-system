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
student* s2;
Club* enteredClub;

void getAllClubNames() const {
    if (Clubs.size() == 0) {
        cout << "No clubs exist in the system." << endl;
        return;
    }
    for (int i = 0; i < Clubs.size(); i++) {
        cout << i + 1 << ". " << Clubs[i].getClubName() << endl;
    }
}
int getTotalNumberOfClubs(){
  return Clubs.size();
}

Student* login(){
  int ID; string password;
  cout<<"Enter ID: ";
  cin>>ID;
  cout<<"Enter password: ";
  cin>>password;
  
  for(int i=0; i<Students.size(); i++){
    if(((Students[i])).getID()==ID && ((Students[i])).checkPassword()==password){
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
    s2=login();
    return s2;
  }else if(num==2){
    s2=login();
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
    cout<<"Enter the number for the command which you want to perform"<<endl;
    int choice; cin>>choice;

    switch(choice){
      case 1:
      getAllClubNames();
      cout<<"Enter the number before the club which you want to join: "<<endl;
      int num;
      cin>>num;
      int noOfClubs=getNoOfClubs();
      Club* currentClub=Clubs[num-1];
      currentClub->getMembers();
      cout<<"Enter 1 to confirm to join the club or enter 2 to return "<<endl;
      int a;
      cin>>a;
      if(a==1){
        s2->joinClubs(currentClub);
        mainMenu();
      }else if(a==2){
        mainMenu();
      }
      case 2:
      enteredClub=(*student).viewMyClubs(student); 
      cout<<"CLUB MENU"<<endl;
      cout<<"1. View Assignments"<<endl;
      cout<<"2. Admin Functions"<<endl;
      cout<<"Enter the number for the command which you want to perform"<<endl;
      int b;
      cin>>b;
      switch(b){
        case 1:

        enteredClub.viewAssignments(s2);
        //remaining idhar thoda sa
        case 2:
        if(enteredClub->isAdmin(s2)){
          cout<<"1. Create assignment"<<endl;
          cout<<"2. Add member"<<endl;
          cout<<"3. Remove member"<<endl;
          cout<<"4. Promote to checker"<<endl;
          cout<<"5. Demote to normnal"<<endl;
          cout<<"6. Change Admin"<<endl;
        }else{
          cout<<"You are not an Admin"<<endl;
          mainMenu();
        }

      }
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