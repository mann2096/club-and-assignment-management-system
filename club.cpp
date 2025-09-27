#include"club.h"
using namespace std;

Club::Club(string name,int id,Student* adminStudent):clubName(name),clubID(id){
  Admin* adminMember=new Admin(adminStudent,this);
  admin=adminMember;
  members.push_back(adminMember);
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
    cout<<"No assignments in this club.\n";
    return;
  }
  cout<<"Assignments in "<<clubName<<":\n";
  for(int i=0;i<assignments.size();i++){
    cout<<i+1<<". "<<assignments[i]->getTitle()<<endl;

    cout<<endl<<"Enter the Number of the Assignment you want to access"<<endl;
    int num; cin>>num;
    cout<<"1.view all assignment submissions"<<endl;
    cout<<"2.view your submissions"<<endl;
    cout<<"3.add a submission"<<endl;
    int num2;
    cout<<"Enter the number for the command you want to implement"<<endl;
    cin>>num2;
    if(num2==1){
      if(isAssignmentChecker(student)){
      assignments[num]->viewSubmissions();
      }else{
        cout<<"To see all submissions you should be a assignment checker"<<endl;
        viewAssignments(student);
      }
    }else if(num2==3){
      string file, timeOfSubmission;
      cout<<"Enter the file"<<endl;
      cin>>file;
      cout<<"Enter the timeOfSubmission"<<endl;
      cin>>timeOfSubmission;
      Submission* sub = new Submission(student, assignments[num], 0, file, timeOfSubmission);
      assignments[num]->addSubmission(sub);
    }else if(num2==2){
      assignments[num]->viewYourSubmissions(student);
    }
  }
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


