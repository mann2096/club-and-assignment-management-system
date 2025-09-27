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
Student* s2;
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
    if(Students[i]->checkPassword(ID, password)){
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
      break;
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
        break;
        case 2:
        if(enteredClub->isAdmin(s2)){
          Admin* admin=enteredClub->getAdmin();
          cout<<"1. Create assignment"<<endl;
          cout<<"2. Add member"<<endl;
          cout<<"3. Remove member"<<endl;
          cout<<"4. Promote to checker"<<endl;
          cout<<"5. Demote to normal"<<endl;
          cout<<"6. Change Admin"<<endl;
          cout<<"Enter the number of the command you want to perform"<<endl;
          int c;
          cin>>c;
          switch(c){
            case 1:
            cout<<"Enter the title of assignment"<<endl;
            string title;
            cin>>title;
            cout<<"Enter the score"<<endl;
            int score;
            cin>>score;
            cout<<"Enter the deadline"<<endl;
            string deadline;//deadline string mei?
            cin>>deadline;
            Assignment* a=new Assignment(title,score,deadline,enteredClub);
            break;
            case 2:
            cout<<"Enter the ID of that student who you want to join in club"<<endl;
            int d;
            cin>>d;
            admin->addMember(d);
            break;
            case 3:
            cout<<"Enter the ID of that student who you want to remove from club"<<endl;
            int e;
            cin>>e;
            admin->removeMember(e);
            break;
            case 4:
            cout<<"Enter the ID of the person that you want to promote to a checker"<<endl;
            int f;
            cin>>f;
            admin->promoteToChecker(f);
            break;
            case 5:
            cout<<"Enter the ID of the person that you want to demote to a normal member"<<endl;
            int g;
            cin>>g;
            admin->demoteToNormal(g);
            break;
            case 6:
            cout<<"Enter the ID of the person that you want to make the new admin"<<endl;
            int g;
            cin>>g;
            admin->changeAdmin();
            break;
          }
        }else{
          cout<<"You are not an Admin"<<endl;
          mainMenu();
        }
        break;
      }
      break;
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