#include<iostream>
#include "Assignment.h"
#include "Submission.h"
#include "Club.h"
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
      int num=(*sub).isLate();
      if(num==0) cout<<"Late Status: No"<<endl;
      else cout<<"Late Status: Yes"<<endl;
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