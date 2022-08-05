#pragma once
#include "student.h"
#include <iostream>

class Roster
{
private:
    int lastIndex = -1;
    static const int numStudents = 5;
    Student* classRosterArray[numStudents]; 
    
public:
    void parser (string row);
    void add(string sID, string fN, string lN, string eMail, int age, int dCourse1, int dCourse2, int dCourse3, DegreeProgram degreePro);
    void printAll();
    void printByDegreeProgram(DegreeProgram degreePro);
    void printInvalidEmails();
    void printAverageDaysInCourse(string StudentID);
    void removeStudent(string sID);
    
    ~Roster();
    
};
