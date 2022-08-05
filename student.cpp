#include "student.h"
#include <iostream>
#include "degree.h"
#include <string>
using std::cout;

Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->studentAge = 0;
    for (int i = 0; i < courseArraySize; i++) {
        this->courseDays[i] = 0;
        this->degreeP = DegreeProgram::SECURITY;
    }
}

Student::Student(string studentID1, string firstName1, string lastName1, string emailAddress1, int studentAge1, int courseDays1[], DegreeProgram degree1)
{
    this->studentID = studentID1;
    this->firstName = firstName1;
    this->lastName = lastName1;
    this->emailAddress = emailAddress1;
    this->studentAge = studentAge1;
    for (int i = 0; i < courseArraySize; i++) {
        this->courseDays[i] = courseDays1[i];
        }
    this->degreeP = degree1;
}

Student::~Student(){}

string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmailAddress() { return emailAddress; }
int Student::getStudentAge() { return studentAge; }
int* Student::getCourseDays() { return this->courseDays; }
DegreeProgram Student::getDegreeProgram() { return degreeP; }

//setters
void Student::setStudentID(string studentID1) { this->studentID = studentID1; }
void Student::setFirstName(string firstName1) { this->firstName = firstName1; }
void Student::setLastName(string lastName1) { this->lastName = lastName1; }
void Student::setEmailAddress(string emailAddress1) { this-> emailAddress = emailAddress1; }
void Student::setStudentAge(int studentAge1) { this-> studentAge = studentAge1; }
void Student::setCourseDays(int courseDays1[])
{
    for (int i = 0; i < courseArraySize; i++) {
        this->courseDays[i] = courseDays1[i];
    }
}

void Student::printFormatHeader()
{
    cout << "STUDENT ID | FIRST NAME | LAST NAME | EMAIL | AGE | DAYS IN COURSE | DEGREE\n" << std::endl;
}

void Student::print()
{
    cout << this->getStudentID() << '\t';
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getStudentAge() << '\t';
    cout << "{" << this->getCourseDays()[0] << ",";
    cout << this->getCourseDays()[1] << ",";
    cout << this->getCourseDays()[2] << "}" << "\t";
    cout << degreeType[this->getDegreeProgram()] << std::endl;
};
