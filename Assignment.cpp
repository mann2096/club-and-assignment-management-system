#include<iostream>
#include "Assignment.h"
#include "Submission.h"
#include "club.h"
using namespace std;

Assignment::Assignment(string title, int score, string deadline, Club* parent) {
    Title=title;
    scoreMax=score;
    Deadline=deadline;
    parentClub=parent;
}


  void Assignment::viewSubmissions(){
    cout<<Title<<endl;
    for(int i=0; i<submissions.size(); i++){
      Submission* sub=submissions[i];
      cout<<(i+1)<<". Student: "<<(*sub).getStudent()<<endl;
      cout<<"Score: "<<(*sub).getScore()<<endl;
      cout<<"File: "<<(*sub).getFile()<<endl;
      if(!sub->isLate()) cout << "Late Status: No" << endl;
      else cout << "Late Status: Yes" << endl;
    }
    cout<<"Enter the number of submission which you want to grade"<<endl;
    int a;
    cin>>a;
    cout<<"Enter the score which you want to give"<<endl;
    int b;
    cin>>b;
    submissions[a-1]->setscore(b);
  }

  void Assignment::viewYourSubmissions(Student* s){
    for(int i=0; i<submissions.size(); i++){
        Student* s2=submissions[i]->getStudent();
        if(s2->getID()==s->getID()){
         Submission* sub=submissions[i];
         cout<<(i+1)<<". Student: "<<(*sub).getStudent()<<endl;
         cout<<"Score: "<<(*sub).getScore()<<endl;
         cout<<"File: "<<(*sub).getFile()<<endl;
         bool num=(*sub).isLate();
         if(!sub->isLate()) cout << "Late Status: No" << endl;
         else cout << "Late Status: Yes" << endl;          
        }
    }
  }
  
 void Assignment::addSubmission(Submission* sub){
    submissions.push_back(sub);
}

string Assignment::getTitle(){
    return Title;
}

Club* Assignment::getParentClub(){
    return parentClub;
}

string Assignment::getDeadline(){
    return Deadline;
}

int Assignment::getScoreMax(){
    return scoreMax;
}