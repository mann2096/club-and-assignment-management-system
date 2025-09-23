#include <string>
using namespace std;

class Student;
class Assignment;

class Submission{
  private:

  Student* submittedBy;
  Assignment* assignment;
  int score;
  string file;
  bool islate;

  public:

  Submission(Student* student1, Assignment* assignment1, int score1, string file1, bool isLate1){
    submittedBy=student1;
    assignment=assignment1;
    score=score1;
    file=file1;
    islate=isLate1;
  }
  
  Student* getStudent(){
    return submittedBy;
  }

  Assignment* getAssignment(){
    return assignment;
  }

  int getScore(){
    return score;
  }

  string getFile(){
    return file;
  }

  bool isLate(){
    return islate;
  }
};