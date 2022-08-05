//
#include "roster.h"
#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;

Roster Roster();
DegreeProgram degreePro;
void Roster::parser(string studentData)
{
    DegreeProgram degreePro = SECURITY;
    if (studentData.back() == 'K') {
        degreePro = NETWORK;
    }
    else if (studentData.back() == 'E')
    { degreePro = SOFTWARE; }
    
    //ID
    char rhs = studentData.find(",");
    string stuID = studentData.substr(0, rhs);
    
    //first name
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstN = studentData.substr(lhs, rhs - lhs);
    
    //last name
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastN = studentData.substr(lhs, rhs - lhs);
    
    //email
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailA = studentData.substr(lhs, rhs - lhs);
    
    //age
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int stuAge = stoi(studentData.substr(lhs, rhs - lhs));
    
    //day 1
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    //day 2
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    //day 3
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int d3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    add(stuID, firstN, lastN, emailA, stuAge, d1, d2, d3, degreePro);
}

//creates student
void Roster::add(string sID, string fN, string lN, string eMail, int age, int dCourse1, int dCourse2, int dCourse3, DegreeProgram degreePro)
{int dArray[3] = {dCourse1, dCourse2, dCourse3};
classRosterArray[++lastIndex] = new Student(sID, fN, lN, eMail, age, dArray, degreePro);

}

//prints all roster info
void Roster::printAll()
{ Student::printFormatHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

//prints specific degree 
void Roster::printByDegreeProgram(DegreeProgram degreePro)
{
    Student::printFormatHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreePro) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

//prints invalid emails
void Roster::printInvalidEmails()
{
    bool valid = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string emailVal = (classRosterArray[i]->getEmailAddress());
        if (emailVal.find('@') == string::npos || (emailVal.find('.') == string::npos)) {
            valid = true;
            cout << classRosterArray[i]->getEmailAddress() << endl;
        }
        else if (emailVal.find(' ') != string::npos) {
            valid = true;
            cout << classRosterArray[i]->getEmailAddress() << endl;
        }
        if (!valid) {
            cout << "none" << endl;
        }
    }
}

//prints average days for student to complete course
void Roster::printAverageDaysInCourse(string StudentID) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        cout << classRosterArray[i]->getStudentID() << " averages";
        cout << (classRosterArray[i]-> getCourseDays()[0] + classRosterArray[i]->getCourseDays()[1] + classRosterArray[i]->getCourseDays()[2])/3 << " days in course." << endl;
    }
    cout << endl;
}

//deletes student
void Roster::removeStudent(string sID) {
    bool found = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == sID) {
            found = true;
            if (i < numStudents - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (found) {
        cout << sID << " REMOVED" << endl << endl;
        this->printAll();
    }
    else cout << sID << " DELETED" << endl;
}

Roster::~Roster(){
    for ( int i = 0; i < numStudents; i++)
    {
        cout << "Destroying " << i + 1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

