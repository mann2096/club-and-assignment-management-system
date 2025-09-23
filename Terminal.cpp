#include <iostream>
#include <string>
//#include "Student.cpp"
//#include "Club.cpp"
#include "Assignment.cpp"
#include "Submission.cpp"
#include "Vector.cpp"
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
    cout<<"3. Exit"<<endl;
    
    int choice; cin>>choice;

    if(choice==1){

    }else if(choice==2){

    }else if(choice==3) return;
    else cout<<"Invalid input"<<endl;
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