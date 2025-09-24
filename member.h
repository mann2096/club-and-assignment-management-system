#include <iostream>
#include <string>
using namespace std;

class Student;
class Club;
class Assignment;

class Member {
protected:
    Student* student;
    Club* club;
    string role;

public:
    Member(Student* s, Club* c, string r);

    Student* getStudent() const;
    Club* getClub() const;
    string getRole() const;

    void display() const;

private:
    void setRole(const string& newRole);
    friend class Admin;
};

// Admin class inheriting Member
class Admin : public Member {
public:
    Admin(Student* s, Club* c);

    void createAssignment(const string& title, int maxScore, const string& deadline);
    void addMember(Student* s);
    void removeMember(int studentID);
    void promoteToChecker(Member* m);
    void demoteToNormal(Member* m);
    void changeAdmin(Member* newAdmin);
};

// AssignmentChecker class inheriting Member
class AssignmentChecker : public Member {
public:
    AssignmentChecker(Student* s, Club* c);
    void gradeAssignment(Assignment* a, Student* s, int score);
};

// NormalMember class inheriting Member
class NormalMember : public Member {
public:
    NormalMember(Student* s, Club* c);
};


