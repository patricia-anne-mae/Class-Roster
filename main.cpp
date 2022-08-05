#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

int main ()
{
    cout << "C867 - Scripting & Programming - Patricia Ubina" << endl;
    cout << "Student ID: #001678170" << endl;
  
    Roster classRoster;
    
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Patricia,Ubina,Pubina1@wgu.edu,24,10,15,25,SOFTWARE" };
    
    const int numStudent = 5;
    
    cout << "PRINTING STUDENT DATA: " << endl;
    for (int i = 0; i < numStudent; i++) {
        classRoster.parser(studentData[i]);
        
    }
    classRoster.printAll();
    cout << endl;
    
    // invalid emails
    cout << "PRINTING INVALID EMAILS: " << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    //course
    cout << "PRINTING AVERAGE DAYS: " << endl;
    classRoster.printAverageDaysInCourse(studentData[4]);
    
    //degree
    cout << "PRINTING DEGREE BY PROGRAM: " << degreeType[2] << endl;
    classRoster.printByDegreeProgram((DegreeProgram)2);
    
    //deleting A3
    cout << "DELETING A3" << endl;
    classRoster.removeStudent("A3");
    cout << endl;
     
    cout << "A3 NOT FOUND" << endl;
    classRoster.removeStudent("A3");
    cout << endl;
     };
