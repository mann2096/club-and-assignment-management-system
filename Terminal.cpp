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


void setupBaseData() {
    // ⿡ Create some students
    Student* s1 = new Student(1, "Alice", "password1");
    Student* s2 = new Student(2, "Bob", "password2");
    Student* s3 = new Student(3, "Charlie", "password3");
    Student* s4 = new Student(4, "David", "password4");
    Student* s5 = new Student(5, "Eve", "password5");
    Student* s6 = new Student(6, "Frank", "password6");
    Student* s7 = new Student(7, "Grace", "password7");
    Student* s8 = new Student(8, "Hank", "password8");

    Students.push_back(s1);
    Students.push_back(s2);
    Students.push_back(s3);
    Students.push_back(s4);
    Students.push_back(s5);
    Students.push_back(s6);
    Students.push_back(s7);
    Students.push_back(s8);

    // ⿢ Create clubs with admins
    Club* club1 = new Club("Chess Club", 101, s1);   // Alice admin
    Club* club2 = new Club("Music Club", 102, s3);   // Charlie admin
    Club* club3 = new Club("Coding Club", 103, s5);  // Eve admin

    Clubs.push_back(club1);
    Clubs.push_back(club2);
    Clubs.push_back(club3);

    // ⿣ Members join clubs
    s2->joinClubs(club1);   // Bob joins Chess
    s4->joinClubs(club1);   // David joins Chess

    s6->joinClubs(club2);   // Frank joins Music
    s7->joinClubs(club2);   // Grace joins Music

    s2->joinClubs(club3);   // Bob joins Coding
    s8->joinClubs(club3);   // Hank joins Coding

    // ⿤ Admins create assignments
    Admin* admin1 = club1->getAdmin(); // Alice
    admin1->createAssignment("Opening Strategies", 100, "2025-10-10");
    admin1->createAssignment("Endgame Tactics", 100, "2025-10-15");

    Admin* admin2 = club2->getAdmin(); // Charlie
    admin2->createAssignment("Compose a Melody", 50, "2025-10-12");
    admin2->createAssignment("Perform a Song", 100, "2025-10-18");

    Admin* admin3 = club3->getAdmin(); // Eve
    admin3->createAssignment("Data Structures Project", 100, "2025-10-20");
    admin3->createAssignment("Debugging Challenge", 75, "2025-10-25");

    // ⿥ Add submissions
    Assignment* c1_a1 = club1->getAssignment()[0];
    Assignment* c1_a2 = club1->getAssignment()[1];

    Assignment* c2_a1 = club2->getAssignment()[0];
    Assignment* c2_a2 = club2->getAssignment()[1];

    Assignment* c3_a1 = club3->getAssignment()[0];
    Assignment* c3_a2 = club3->getAssignment()[1];

    // Chess submissions
    Submission* sub1 = new Submission(s2, c1_a1, 0, "s2_opening.pdf", "2025-09-27");
    Submission* sub2 = new Submission(s4, c1_a1, 0, "s4_opening.pdf", "2025-09-27");
    c1_a1->addSubmission(sub1);
    c1_a1->addSubmission(sub2);

    // Music submissions
    Submission* sub3 = new Submission(s6, c2_a1, 0, "s6_melody.mp3", "2025-09-28");
    Submission* sub4 = new Submission(s7, c2_a1, 0, "s7_melody.mp3", "2025-09-28");
    c2_a1->addSubmission(sub3);
    c2_a1->addSubmission(sub4);

    // Coding submissions
    Submission* sub5 = new Submission(s2, c3_a1, 0, "s2_ds_project.zip", "2025-09-29");
    Submission* sub6 = new Submission(s8, c3_a1, 0, "s8_ds_project.zip", "2025-09-29");
    c3_a1->addSubmission(sub5);
    c3_a1->addSubmission(sub6);

    // ⿦ Promote some members to checkers
    admin1->promoteToChecker(2); // Bob becomes checker in Chess Club
    admin2->promoteToChecker(6); // Frank becomes checker in Music Club
    admin3->promoteToChecker(8); // Hank becomes checker in Coding Club
}




void getAllClubNames() {
    if (Clubs.size() == 0) {
        cout << "No clubs exist in the system." << endl;
        return;
    }
    for (int i = 0; i < Clubs.size(); i++) {
        cout << i + 1 << ". " << Clubs[i]->getClubName() << endl;
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

    int ID; 
    string name,password;

    cout<<"Enter your ID"<<endl;
    cin>>ID;
    cout<<"Enter your name"<<endl;
    getline(cin, name);
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
      case 1:{
      getAllClubNames();
      cout<<"Enter the number before the club which you want to join: "<<endl;
      int num;
      cin>>num;

      Club* currentClub=Clubs[num-1];
      currentClub->getMembers();
      cout<<"Enter 1 to confirm to join the club or enter 2 to return "<<endl;
      int a;
      cin>>a;
      if(a==1){
        s2->joinClubs(currentClub);
      }
      break;
      }
      case 2:{
      enteredClub=student->viewMyClubs(student); 
      if(enteredClub==nullptr){
        break;
      }
      cout<<"CLUB MENU"<<endl;
      cout<<"1. View Assignments"<<endl;
      cout<<"2. Admin Functions"<<endl;
      cout<<"3.EXIT"<<endl;
      cout<<"Enter the number for the command which you want to perform"<<endl;
      int b;
      cin>>b;
      switch(b){
        case 1:
        enteredClub->viewAssignments(s2);
        continue;
        case 2:
        if(enteredClub->isAdmin(s2)){
          Admin* admin=enteredClub->getAdmin();
          cout<<"1. Create assignment"<<endl;
          cout<<"2. Add member"<<endl;
          cout<<"3. Remove member"<<endl;
          cout<<"4. Promote to checker"<<endl;
          cout<<"5. Demote to normal"<<endl;
          cout<<"6. Change Admin"<<endl;
          cout<<"Enter the number of the command you want to perform or 0 to exit"<<endl;
          int c;
          cin>>c;
          switch(c){
            case 0:{
              break;
            }
            case 1:{
            cout<<"Enter the title of assignment"<<endl;
            string title;
            getline(cin, title);
            cout<<"Enter the score"<<endl;
            int score;
            cin>>score;
            cout<<"Enter the deadline"<<endl;
            string deadline;//deadline string mei?
            cin>>deadline;
            Assignment* a=new Assignment(title,score,deadline,enteredClub);
            enteredClub->addAssignment(a);
            break;
            }
            case 2:{
            cout<<"Enter the ID of that student who you want to join in club"<<endl;
            int d;
            cin>>d;
            admin->addMember(d);
            break;
            }
            case 3:{
            cout<<"Enter the ID of that student who you want to remove from club"<<endl;
            int e;
            cin>>e;
            admin->removeMember(e);
            break;
            }
            case 4:{
            cout<<"Enter the ID of the person that you want to promote to a checker"<<endl;
            int f;
            cin>>f;
            admin->promoteToChecker(f);
            break;
            }
            case 5:{
            cout<<"Enter the ID of the person that you want to demote to a normal member"<<endl;
            int g;
            cin>>g;
            admin->demoteToNormal(g);
            break;
            }
            case 6:{
            cout<<"Enter the ID of the person that you want to make the new admin"<<endl;
            int g;
            cin>>g;
            admin->changeAdmin(g);
            break;
            }
          }
        }else{
          cout<<"You are not an Admin"<<endl;
        }
        break;
      }
      break;
      }
      case 3:{
      return;
      }
    }
  }
}

int main(){

  setupBaseData();
 
  while(true){
  cout<<"CLUB AND ASSIGNMENT MANAGAMENT SYSTEM"<<endl;
  Student* student=nullptr;
  while(student==nullptr){
    student=FirstMenu();
  }
  mainMenu(student);

}
return 0;
}