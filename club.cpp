#include <iostream>
#include <string>
using namespace std;

class Club {
private:
    string clubName;
    int clubID;                 
    Vector<Member*> members;         
    Vector<Assignment*> assignments; 

public:
    Club(string name, int id, Student* adminStudent):clubName(name),clubID(id) {
        Member* adminMember = new Member(adminStudent, this, "Admin");
        members.push_back(adminMember);
    }
    string getClubName()const{
        return clubName;
    }

    Member* getAdmin()const{
        for(auto m:members){
            if(m->getRole()=="Admin")return m;
        }
        return nullptr;
    }

    void getMembers()const{
        cout<<"Members of "<<clubName<<":\n";
        for(int i=0; i <members.size();i++){
            cout<<"- "<<members[i]->getStudent()->getName()<<" ("<<members[i]->getRole()<<")"<<endl;
        }
    }


    void viewAssignments()const{
    if(assignments.size()==0){
        cout<<"No assignments in this club.\n";
        return;
    }

    cout<<"Assignments in "<<clubName<<":\n";
    for(int i=0;i<assignments.size();i++){
        cout<<i+1<<". "<<assignments[i]->getTitle()<<endl;
    }
}

    vector<Member*>getAssignmentCheckers()const{
        vector<Member*> checkers;
        for(auto m:members){
            if(m->getRole()=="AssignmentChecker") checkers.push_back(m);
        }
        return checkers;
    }

    void joinClubNoCheck(Student* s){
        Member* m=new Member(s,"Normal");
        members.push_back(m);
    }
};
