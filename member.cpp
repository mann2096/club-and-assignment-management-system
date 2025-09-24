#include<iostream>
#include <string>
#include "Assignment.cpp"
#include "Vector.cpp"
#include "Submission.cpp"
#include "club.cpp"
#include "Student.cpp"
using namespace std;
class Member{
protected:
    Student* student;
    Club* club;
    string role;

public:
    Member(Student* s,Club* c,string r):student(s),club(c),role(r){}
    Student* getStudent()const{return student;}
    Club* getClub()const{return club;}
    string getRole()const{return role;}

    void display()const{
        cout<<"Student: "<<student->getName()<<" (Role: " << role << ")"<<endl;
    }

private:
    void setRole(const string& newRole){role=newRole;}
    friend class Admin;
};

class Admin:public Member{
public:
    Admin(Student* s,Club* c):Member(s,c,"Admin"){}

    void createAssignment(const string& title,int maxScore,const string& deadline){
        Assignment* a=new Assignment(title,maxScore,deadline);
        club->addAssignment(a);
        cout<<"Assignment '"<<title<<"' created in club "<<club->getClubName()<<endl;
    }

    void addMember(Student* s){
        club->addMember(s);
        cout<<"Student added to club: "<<club->getClubName()<<endl;
    }

    void removeMember(int studentID){
        club->removeMember(studentID);
        cout<<"Student removed from club: "<<club->getClubName()<<endl;
    }

    void promoteToChecker(Member* m){
        m->setRole("AssignmentChecker");
        cout<<"Promoted "<<m->getStudent()->getName()<<" to AssignmentChecker."<<endl;
    }

    void demoteToNormal(Member* m){
        m->setRole("Normal");
        cout<<"Demoted "<<m->getStudent()->getName()<<" to Normal member."<<endl;
    }

    void changeAdmin(Member* newAdmin){
        if(newAdmin->getClub()!=club){
            cout<<"Error: Member does not belong to this club."<<endl;
            return;
        }
        this->setRole("Normal");
        newAdmin->setRole("Admin");
        cout<<"Admin changed to "<<newAdmin->getStudent()->getName()<<endl;
    }
};

class AssignmentChecker:public Member{
public:
    AssignmentChecker(Student* s,Club* c):Member(s,c,"AssignmentChecker"){}
    void gradeAssignment(Assignment* a,Student* s,int score){
        cout<<"Grading assignment '"<<a->getTitle()<<"' for student "<<s->getName()<<" with score "<<score<<endl;
    }
};
class NormalMember:public Member{
public:
    NormalMember(Student* s,Club* c):Member(s,c,"Normal"){}
};
