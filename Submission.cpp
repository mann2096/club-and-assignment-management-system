#include "Submission.h"
#include "Assignment.h"
using namespace std;

Submission::Submission(Student* student1,Assignment* assignment1,int score1,string file1,string timeOfSubmission){
  submittedBy=student1;
  assignment=assignment1;
  score=score1;
  file=file1;
  late=false;
  string deadline=assignment->getDeadline();
  for(int i=0;i<deadline.size()&&i<timeOfSubmission.size();i++){
    if(timeOfSubmission[i]>deadline[i]){
      late=true;
      break;
    }
  }
}

void Submission::setScore(int s){
  score=s;
}

Student* Submission::getStudent(){
  return submittedBy;
}

Assignment* Submission::getAssignment(){
  return assignment;
}

int Submission::getScore(){
  return score;
}

string Submission::getFile(){
  return file;
}

bool Submission::isLate(){
  return late;
}
