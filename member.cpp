#include"member.h"
#include "club.h"
using namespace std;
extern Vector<Student*> Students;

Member::Member(Student* s,Club* c,string r):student(s),club(c),role(r){}

Student* Member::getStudent()const{return student;}

Club* Member::getClub()const{return club;}

string Member::getRole()const{return role;}

void Member::display()const{
  cout<<"Student: "<<student->getName()<<" (Role: "<<role<<")"<<endl;
}

void Member::setRole(const string& newRole){role=newRole;}

Admin::Admin(Student* s,Club* c):Member(s,c,"Admin"){}

void Admin::createAssignment(const string& title,int maxScore,const string& deadline){
  Assignment* a=new Assignment(title, maxScore, deadline, club);
  club->addAssignment(a);
  cout<<"Assignment '"<<title<<"' created in club "<<club->getClubName()<<endl;
}

void Admin::addMember(int studentID){
  for(int i=0; i<Students.size(); i++){
    int ID=Students[i]->getID();
    if(ID==studentID){
      club->joinClubNoCheck(Students[i]);
      cout<<"Student added to club: "<<club->getClubName()<<endl;
    }
  }
}

void Admin::removeMember(int studentID){
  club->removeMember(studentID);
  cout<<"Student removed from club: "<<club->getClubName()<<endl;
}

void Admin::promoteToChecker(int studentID) {
    for (int i = 0; i < club->members.size(); i++) {
        Student* s2 = club->members[i]->getStudent();
        if (s2->getID() == studentID) {
            Student* s = s2;
            Club* c = club;
            delete club->members[i];
            AssignmentChecker* checker = new AssignmentChecker(s, c);
            club->members[i] = checker;
            club->assignmentCheckers.push_back(checker);

            cout << "Promoted " << s->getName() << " to AssignmentChecker." << endl;
            return;
        }
    }

    cout << "No member found with ID " << studentID 
         << " in club " << club->getClubName() << endl;
}


void Admin::demoteToNormal(int studentID) {
    for (int i = 0; i < club->members.size(); i++) {
        Member* m = club->members[i];
        Student* s = m->getStudent();

        if (s->getID() == studentID) {
            delete club->members[i];
            NormalMember* normal = new NormalMember(s, club);
            club->members[i] = normal;
            for (int j = 0; j < club->assignmentCheckers.size(); j++) {
                if (club->assignmentCheckers[j]->getStudent()->getID() == studentID) {
                    club->assignmentCheckers.remove(j);
                    break;
                }
            }

            cout << "Demoted " << s->getName() << " to Normal member." << endl;
            return;
        }
    }

    cout << "No member found with ID " << studentID << " in club " 
         << club->getClubName() << endl;
}


void Admin::changeAdmin(int studentID) {
    int newAdminIndex = -1;

    for (int i = 0; i < club->members.size(); i++) {
        if (club->members[i]->getStudent()->getID() == studentID) {
            newAdminIndex = i;
            break;
        }
    }

    if (newAdminIndex == -1) {
        cout << "No member found with ID " << studentID 
             << " in club " << club->getClubName() << endl;
        return;
    }

    for (int i = 0; i < club->members.size(); i++) {
        if (club->members[i] == club->admin) {
            Student* oldAdminStudent = club->admin->getStudent();
            delete club->members[i];
            club->members[i] = new NormalMember(oldAdminStudent, club);
            break;
        }
    }

    for (int j = 0; j < club->assignmentCheckers.size(); j++) {
        if (club->assignmentCheckers[j]->getStudent()->getID() == studentID) {
            club->assignmentCheckers.remove(j);
            break;
        }
    }

    Student* newAdminStudent = club->members[newAdminIndex]->getStudent();
    delete club->members[newAdminIndex];   
    Admin* newAdminObj = new Admin(newAdminStudent, club);
    club->members[newAdminIndex] = newAdminObj;
    club->admin = newAdminObj;

    cout << "Admin changed to " << newAdminStudent->getName() << endl;
}




AssignmentChecker::AssignmentChecker(Student* s,Club* c):Member(s,c,"AssignmentChecker"){}
void AssignmentChecker::gradeAssignment(Assignment* a,Student* s,int score){
  cout<<"Grading assignment '"<<a->getTitle()<<"' for student "<<s->getName()<<" with score "<<score<<endl;
}

NormalMember::NormalMember(Student* s,Club* c):Member(s,c,"Normal"){}
