#include<iostream>
#include <string>
#include "club.cpp"
using namespace std;

class Student{
private:
    string name;
    int id;
    string password;
    Vector<Club*> joinedClubs;
    Vector<Submission*> submissions;

public:
    Student(int id,string name,string password):id(id),name(name),password(password){}

    int getID() const{return id}
    string getName() const{return name}

    bool checkPassword(int enteredID,string enteredPassword){
        return(enteredID==id&&enteredPassword==password);
    }

    void joinClubs(Club* c) {
    if (c != nullptr) {
        joinedClubs.push_back(c);  
        c->addMember(this);        
        }   
    }

    void viewMyClubs(){
        cout<<"Clubs for "<<name<<" (ID: " << id << "):"<<endl;
        for(int i = 0;i<joinedClubs.size();i++) {
            cout<<"- "<<joinedClubs[i]->getClubName()<< endl;
        }
    }

    void submitAssignment(Assignment* a,string file){
        Submission* s=new Submission(this,a,file);
        submissions.push_back(s);
        a->addSubmission(s);
    }

    void viewSubmissions() const {
        cout<<"Submissions for "<<name<<" (ID: "<<id<< "):"<<endl;
        for (auto s:submissions){
            if(s){
                cout<<"- Assignment: "<<s->getAssignment()->getTitle()<<" | File: "<<s->getFile()<<" | Score: "<<s->getScore()<<(s->isLate()?" | Late":"on time")<<endl;
            }
        }
    }
};
