#include <iostream>
#include <string>
using namespace std;

// Forward declarations to avoid circular dependency
class Club;
class Assignment;
class Submission;
template <typename T> class Vector; // Your custom Vector class

class Student {
private:
    string name;
    int id;
    string password;
    Vector<Club*> joinedClubs;
    Vector<Submission*> submissions;

public:
    // Constructor
    Student(int id, string name, string password);

    // Accessors
    int getID() const;
    string getName() const;

    // Authentication
    bool checkPassword(int enteredID, string enteredPassword);

    // Club actions
    void joinClubs(Club* c);
    void viewMyClubs() const;

    // Assignment actions
    void submitAssignment(Assignment* a, string file);
    void viewSubmissions() const;
};