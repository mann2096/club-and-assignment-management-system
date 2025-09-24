#include <string>
#include "Vector.cpp"
#include "Submission.cpp"
#include <iostream>
using namespace std;

class Club;
class Submission;

class Assignment{
  private:

  Club* parentClub;
  string Title;
  int scoreMax;
  string Deadline;
  Vector<Submission*> submissions;

  public:

  void viewSubmissions(){
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
  
  void addSubmission(Submission* sub){
    submissions.push_back(sub);
  }

  string getTitle(){
    return Title;
  }

  Club* getParentClub(){
    return parentClub;
  }

  string getDeadline(){
    return Deadline;
  }

  int getScoreMax(){
    return scoreMax;
  }
};