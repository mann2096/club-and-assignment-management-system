#include <iostream>
#include "Assignment.h"
#include "Submission.h"
#include "Student.h"
using namespace std;


Assignment::Assignment(string title, int score, string deadline, Club* parent) {
    Title=title;
    scoreMax=score;
    Deadline=deadline;
    parentClub=parent;
}


  void Assignment::viewSubmissions(){
    if(submissions.size()==0){
      cout<<"No submissions have been made for this assignment"<<endl;
      return;
    }
    cout<<Title<<endl;
    for(int i=0; i<submissions.size(); i++){
      Submission* sub=submissions[i];
      cout<<(i+1)<<". Student: "<<((sub->getStudent())->getName())<<endl;
      cout<<"Score: "<<(*sub).getScore()<<endl;
      cout<<"File: "<<(*sub).getFile()<<endl;
      if(!sub->isLate()) cout << "Late Status: No" << endl<<endl;
      else cout << "Late Status: Yes" << endl<<endl;
    }
    cout<<"Enter the number of the submission you want to grade"<<endl;
    int a;
    cin>>a;
    if(a>submissions.size()){
      cout<<"No such submission exists yet"<<endl;
      return;
    }
    cout<<"Enter the score you want to give"<<endl;
    int b;
    cin>>b;
    submissions[a-1]->setScore(b);
  }

  void Assignment::viewYourSubmissions(Student* s){
    int ct=0;
    for(int i=0; i<submissions.size(); i++){
        Student* s2=submissions[i]->getStudent();
        if(s2->getID()==s->getID()){
          ct++;
         Submission* sub=submissions[i];
         cout<<(ct)<<". Student: "<<((sub->getStudent())->getName())<<endl;
         cout<<"Score: "<<(*sub).getScore()<<endl;
         cout<<"File: "<<(*sub).getFile()<<endl;
         bool num=(*sub).isLate();
         if(!num) cout << "Late Status: No" << endl;
         else cout << "Late Status: Yes" << endl;          
        }
    }
    if(ct==0) cout<<"You have no submissions for this assignment"<<endl;
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