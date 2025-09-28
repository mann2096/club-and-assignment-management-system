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
    Student* s1  = new Student(1,  "Atharv",   "pass1");
    Student* s2  = new Student(2,  "Swastik",  "pass2");
    Student* s3  = new Student(3,  "Somye",    "pass3");
    Student* s4  = new Student(4,  "Stuti",    "pass4");
    Student* s5  = new Student(5,  "Shradha",  "pass5");
    Student* s6  = new Student(6,  "Khushi",   "pass6");
    Student* s7  = new Student(7,  "Rudra",    "pass7");
    Student* s8  = new Student(8,  "Darshan",  "pass8");
    Student* s9  = new Student(9,  "Saksham",  "pass9");
    Student* s10 = new Student(10, "Sasmit",   "pass10");
    Student* s11 = new Student(11, "Pulkit",   "pass11");
    Student* s12 = new Student(12, "Ameya",    "pass12");
    Student* s13 = new Student(13, "Kabeer",   "pass13");
    Student* s14 = new Student(14, "Divyansh", "pass14");
    Student* s15 = new Student(15, "Pranav",   "pass15");

    Students.push_back(s1); Students.push_back(s2); Students.push_back(s3);
    Students.push_back(s4); Students.push_back(s5); Students.push_back(s6);
    Students.push_back(s7); Students.push_back(s8); Students.push_back(s9);
    Students.push_back(s10); Students.push_back(s11); Students.push_back(s12);
    Students.push_back(s13); Students.push_back(s14); Students.push_back(s15);

    Club* club1 = new Club("IMG",      201, s1);
    Club* club2 = new Club("SDS",      202, s4);
    Club* club3 = new Club("Robocon",  203, s7);
    Club* club4 = new Club("E-Cell",   204, s10);

    Clubs.push_back(club1);
    Clubs.push_back(club2);
    Clubs.push_back(club3);
    Clubs.push_back(club4);

    s2->joinClubs(club1);
    s3->joinClubs(club1);
    s4->joinClubs(club1);

    s5->joinClubs(club2);
    s6->joinClubs(club2);
    s7->joinClubs(club2);

    s8->joinClubs(club3);
    s9->joinClubs(club3);
    s10->joinClubs(club3);

    s11->joinClubs(club4);
    s12->joinClubs(club4);
    s13->joinClubs(club4);
    s14->joinClubs(club4);
    s15->joinClubs(club4);

    Admin* admin1 = club1->getAdmin();
    admin1->createAssignment("IMG Design Challenge", 100, "2025-10-05");
    admin1->createAssignment("Photography Contest",  80,  "2025-10-08");

    Admin* admin2 = club2->getAdmin();
    admin2->createAssignment("ML Model Training",    100, "2025-10-06");
    admin2->createAssignment("Data Analysis Task",   90,  "2025-10-09");

    Admin* admin3 = club3->getAdmin();
    admin3->createAssignment("Robot Arm Build",      120, "2025-10-07");
    admin3->createAssignment("Circuit Debugging",    75,  "2025-10-11");

    Admin* admin4 = club4->getAdmin();
    admin4->createAssignment("Startup Pitch Deck",   100, "2025-10-12");
    admin4->createAssignment("Market Research",      70,  "2025-10-15");

    club1->getAssignment()[0]->addSubmission(new Submission(s2, club1->getAssignment()[0], 0, "swastik_design.pdf", "2025-09-28"));
    club1->getAssignment()[0]->addSubmission(new Submission(s3, club1->getAssignment()[0], 0, "somye_design.pdf",   "2025-09-28"));
    club1->getAssignment()[1]->addSubmission(new Submission(s4, club1->getAssignment()[1], 0, "stuti_photo.jpg",   "2025-09-29"));
    club1->getAssignment()[1]->addSubmission(new Submission(s1, club1->getAssignment()[1], 0, "atharv_photo.jpg",  "2025-09-29"));


    club2->getAssignment()[0]->addSubmission(new Submission(s5, club2->getAssignment()[0], 0, "shradha_ml.ipynb", "2025-09-30"));
    club2->getAssignment()[0]->addSubmission(new Submission(s6, club2->getAssignment()[0], 0, "khushi_ml.ipynb",  "2025-09-30"));
    club2->getAssignment()[1]->addSubmission(new Submission(s7, club2->getAssignment()[1], 0, "rudra_data.csv",   "2025-10-01"));
    club2->getAssignment()[1]->addSubmission(new Submission(s4, club2->getAssignment()[1], 0, "stuti_data.csv",   "2025-10-01"));

    club3->getAssignment()[0]->addSubmission(new Submission(s8,  club3->getAssignment()[0], 0, "darshan_robot.pdf", "2025-10-02"));
    club3->getAssignment()[0]->addSubmission(new Submission(s9,  club3->getAssignment()[0], 0, "saksham_robot.pdf", "2025-10-02"));
    club3->getAssignment()[1]->addSubmission(new Submission(s10, club3->getAssignment()[1], 0, "sasmit_circuit.png","2025-10-03"));
    club3->getAssignment()[1]->addSubmission(new Submission(s7,  club3->getAssignment()[1], 0, "rudra_circuit.png", "2025-10-03"));

    club4->getAssignment()[0]->addSubmission(new Submission(s11, club4->getAssignment()[0], 0, "pulkit_pitch.pptx", "2025-10-04"));
    club4->getAssignment()[0]->addSubmission(new Submission(s12, club4->getAssignment()[0], 0, "ameya_pitch.pptx",  "2025-10-04"));
    club4->getAssignment()[1]->addSubmission(new Submission(s13, club4->getAssignment()[1], 0, "kabeer_market.pdf", "2025-10-05"));
    club4->getAssignment()[1]->addSubmission(new Submission(s14, club4->getAssignment()[1], 0, "divyansh_market.pdf","2025-10-05"));

    admin1->promoteToChecker(2);  
    admin2->promoteToChecker(5);  
    admin3->promoteToChecker(9);   
    admin4->promoteToChecker(12);  

    cout << "Base data setup complete: 15 students, 4 clubs, 8 assignments, 16+ submissions." << endl;
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
    cin>>ID;cin.ignore();
    cout<<"Enter your name"<<endl;
    getline(cin, name);
    cout<<"Enter your password"<<endl;
    getline(cin, password);
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
    cout<<"4. Create a Club"<<endl;
    cout<<"Enter the number of the command you want to perform"<<endl;
    int choice; cin>>choice;

    switch(choice){
      case 1:{
      getAllClubNames();
      cout<<"Enter the number of the club you want to join: "<<endl;
      int num;
      cin>>num;
      Club* currentClub=Clubs[num-1];
      currentClub->getMembers();
      cout<<"Enter 1 to confirm to join the club or 0 to exit"<<endl;
      int a;
      cin>>a;
      if(a==1){
        if(currentClub->alreadyMember(student)){
          cout<<"You are already a member"<<endl;
        }else s2->joinClubs(currentClub);
      }
      break;
      }
      case 2:{
      enteredClub=student->viewMyClubs(student); 
      if(enteredClub==nullptr){
        break;
      }
      cout<<endl;
      cout<<"CLUB MENU"<<endl;
      cout<<"1. View Assignments"<<endl;
      cout<<"2. Admin Functions"<<endl;
      cout<<"3. Exit"<<endl;
      cout<<"Enter the number of the command you want to perform"<<endl;
      int b;
      cin>>b;
      switch(b){
        case 1:
        enteredClub->viewAssignments(s2);
        continue;
        case 2:
        if(enteredClub->isAdmin(s2)){
          Admin* admin=enteredClub->getAdmin();
          cout<<endl;
          cout<<"1. Create assignment"<<endl;
          cout<<"2. Add member"<<endl;
          cout<<"3. Remove member"<<endl;
          cout<<"4. Promote to checker"<<endl;
          cout<<"5. Demote to member"<<endl;
          cout<<"6. Change Admin"<<endl;
          cout<<"Enter the number of the command you want to perform or 0 to exit"<<endl;
          int c;
          cin>>c;
          switch(c){
            case 0:{
              break;
            }
            case 1:{
            cout<<"Enter the title of the assignment"<<endl;
            string title;
            cin.ignore();
            getline(cin, title);
            cout<<"Enter the maximum obtainable score"<<endl;
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
            cout<<"Enter the ID of the student you want to join the club"<<endl;
            int d;
            cin>>d;
            admin->addMember(d);
            break;
            }
            case 3:{
            cout<<"Enter the ID of the student you want to remove from the club"<<endl;
            int e;
            cin>>e;
            admin->removeMember(e);
            break;
            }
            case 4:{
            cout<<"Enter the ID of the person you want to promote to a checker"<<endl;
            int f;
            cin>>f;
            admin->promoteToChecker(f);
            break;
            }
            case 5:{
            cout<<"Enter the ID of the person you want to demote to a normal member"<<endl;
            int g;
            cin>>g;
            admin->demoteToNormal(g);
            break;
            }
            case 6:{
            cout<<"Enter the ID of the person you want to make the new admin"<<endl;
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
      case 4:{
        string w; cin.ignore();
        cout<<"Enter the Name of your club"<<endl;
        getline(cin, w);
        int z=Clubs.size()+1;
        Club* club4 = new Club(w, z, s2);
        Clubs.push_back(club4);
        break;
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