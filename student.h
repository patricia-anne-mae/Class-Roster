#pragma once
#include <string>
using std::string;
#include "degree.h"


class Student
{
public:
    const static int courseArraySize = 3;
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int studentAge;
    int courseDays[courseArraySize];
    DegreeProgram degreeP;

public:
    //constructor
    Student();
    
    //full constructor
    Student(string studentID1, string firstName1, string lastName1, string emailAddress1, int studentAge1, int courseDays1[], DegreeProgram degree1);
    
    //deconstructor
    ~Student();
    
    //getters (accessors)
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getStudentAge();
    int* getCourseDays();
    DegreeProgram getDegreeProgram();
    
    //setters (mutators)
    void setStudentID(string studentID1);
    void setFirstName(string firstName1);
    void setLastName(string lastName1);
    void setEmailAddress(string emailAddress1);
    void setStudentAge(int studentAge1);
    void setCourseDays(int courseDays1[]);
    void setDegree(DegreeProgram degree1);
    
    static void printFormatHeader();
    virtual void print();   
};
