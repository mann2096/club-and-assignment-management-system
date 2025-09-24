#include <iostream>
#include <string>
using namespace std;

// Forward declarations to avoid circular dependency
class Student;
class Member;
class Assignment;
template <typename T> class Vector; // Your custom Vector class

class Club {
private:
    string clubName;
    int clubID;                 
    Vector<Member*> members;         
    Vector<Assignment*> assignments; 

public:
    // Constructor
    Club(string name, int id, Student* adminStudent);

    // Accessors
    string getClubName() const;
    Member* getAdmin() const;
    void getMembers() const;
    void viewAssignments() const;
    Vector<Member*> getAssignmentCheckers() const;

    // Student actions
    void joinClubNoCheck(Student* s);
};