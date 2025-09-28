#include"club.h"
#include "member.h"
#include "Submission.h"
using namespace std;

Club::Club(string name,int id,Student* adminStudent):clubName(name),clubID(id){
  Admin* adminMember=new Admin(adminStudent,this);
  admin=adminMember;
  members.push_back(adminMember);
  adminStudent->adminCreatesClub(this);
}

string Club::getClubName()const{
  return clubName;
}

Admin* Club::getAdmin()const{
  return admin;
}

void Club::getMembers()const{
  cout<<"Members of "<<clubName<<":\n";
  for(int i=0;i<members.size();i++){
    cout<<"- "<<members[i]->getStudent()->getName()<<" ("<<members[i]->getRole()<<")"<<endl;
  }
}

bool Club::isAdmin(Student* s)const{
  bool flag=false;
  int id=s->getID();
  int id2=admin->getStudent()->getID();
  if(id==id2){
    flag=true;;
  }
  return flag;
}

bool Club::isAssignmentChecker(Student* s)const{
  bool flag=false;
  int id=s->getID();
  for(int i=0; i<members.size(); i++){
    Student* s2=members[i]->getStudent();
    int id2=s2->getID();
    if(id==id2){
      if(members[i]->getRole()=="AssignmentChecker"){
        flag=true; break;
      }
    }
  }
  return flag;
}

void Club::viewAssignments(Student* student)const{
  if(assignments.size()==0){
    cout<<"No assignments in this club"<<endl;
    return;
  }
  cout<<"Assignments in "<<clubName<<":\n";
  for(int i=0;i<assignments.size();i++){
    cout<<i+1<<". "<<assignments[i]->getTitle()<<"                 Deadline:"<<assignments[i]->getDeadline()<<endl;}

    cout<<endl<<"Enter the Number of the Assignment you want to access or enter 0 to exit"<<endl;
    int num; cin>>num;
    if(num==0){
      return;
    }
    cout<<endl;
    cout<<"1. View all assignment submissions"<<endl;
    cout<<"2. View your submissions"<<endl;
    cout<<"3. Add a submission"<<endl;
    cout<<"4. Return to Main Menu"<<endl;
    int num2;
    cout<<"Enter the number of the command you want to implement"<<endl;
    cin>>num2;
    if(num2==1){
      if(isAssignmentChecker(student)){
      assignments[num-1]->viewSubmissions();
      }else{
        cout<<"To see all submissions, you should be an assignment checker"<<endl;
        viewAssignments(student);
      }
    }else if(num2==3){
      string file, timeOfSubmission;
      cout<<"Enter the file"<<endl;
      cin.ignore();
      getline(cin, file);
      cout<<"Enter the time Of Submission"<<endl;
      cin>>timeOfSubmission;
      Submission* sub = new Submission(student, assignments[num-1], 0, file, timeOfSubmission);
      assignments[num-1]->addSubmission(sub);
      viewAssignments(student);
    }else if(num2==2){
      assignments[num-1]->viewYourSubmissions(student);
      string input;
      cout<<"Enter anything to return back"<<endl;
      cin>>input;
      viewAssignments(student);
    }else if(num2==4){
      return;
    }
  
}


Vector<Assignment*> Club::getAssignment() const {
    return assignments;
}

bool Club::alreadyMember(Student* s) const{
  for(int i=0; i<members.size(); i++){
    if((members[i]->getStudent())->getID()==s->getID()) return true;
  }
  return false;
}

void Club::joinClubNoCheck(Student* s){
  NormalMember* m=new NormalMember(s,this);
  members.push_back(m);
}

void Club::removeMember(int studentID) {
    for (int i = 0; i < members.size(); i++) {
        if (members[i]->getStudent()->getID() == studentID) {
            delete members[i];          
            members.remove(i);          
            cout << "Removed student with ID " << studentID 
                 << " from club " << clubName << endl;
            return;
        }
    }
    cout << "Student with ID " << studentID << " not found in this club." << endl;
}

void Club::addAssignment(Assignment* a) {
    assignments.push_back(a);
}


