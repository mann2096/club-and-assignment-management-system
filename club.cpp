#include"club.h"
using namespace std;

Club::Club(string name,int id,Student* adminStudent):clubName(name),clubID(id){
  Member* adminMember=new Member(adminStudent,this,"Admin");
  members.push_back(adminMember);
}

string Club::getClubName()const{
  return clubName;
}

Member* Club::getAdmin()const{
  for(int i=0;i<members.size();i++){
    if(members[i]->getRole()=="Admin") return members[i];
  }
  return nullptr;
}

void Club::getMembers()const{
  cout<<"Members of "<<clubName<<":\n";
  for(int i=0;i<members.size();i++){
    cout<<"- "<<members[i]->getStudent()->getName()<<" ("<<members[i]->getRole()<<")"<<endl;
  }
}

bool Club::isAdmin(Student* s){
  bool flag=false;
  int id=s->getID();
  for(int i=0; i<members.size(); i++){
    Student* s2=members[i]->getStudent();
    int id2=s2->getID();
    if(id==id2){
      if(members[i]->getRole()=="Admin"){
        flag=true; break;
      }
    }
  }
  return flag;
}

void Club::viewAssignments(Student* student)const{
  if(assignments.size()==0){
    cout<<"No assignments in this club.\n";
    return;
  }
  cout<<"Assignments in "<<clubName<<":\n";
  for(int i=0;i<assignments.size();i++){
    cout<<i+1<<". "<<assignments[i].getTitle()<<endl;

    cout<<endl<<"Enter the Number of the Assignment you want to access"<<endl;
    int num; cin>>num;
    cout<<"Enter 1 to view all assignment submissions, 2 to view your submissions and 3 to add a submission"<<endl;
    int num2; cin>>num2;
    if(num2==1){
      //Assignment checker
      assignments[num]->viewSubmissions();
    }else if(num2==3){
      cout<<"Enter the submission in this format: file, timeOfSubmission"<<endl;
      string file, timeOfSubmission; cin>>file>>timeOfSubmission;
      Submission* sub=new Submission(student, *(assignments[num]), file, timeOfSubmission);
      assignments[num]->addSubmission(sub);
    }else if(num2==2){
      assignments[num]->viewYourSubmissions(student);
    }
  }
}

vector<Member*> Club::getAssignmentCheckers()const{
  vector<Member*> checkers;
  for(int i=0;i<members.size();i++){
    if(members[i]->getRole()=="AssignmentChecker") checkers.push_back(members[i]);
  }
  return checkers;
}

void Club::joinClubNoCheck(Student* s){
  Member* m=new Member(s,this,"Normal");
  members.push_back(m);
}
