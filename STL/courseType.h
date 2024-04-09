

#ifndef DATASTRUCTURES_COURSETYPE_H
#define DATASTRUCTURES_COURSETYPE_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class courseType {
public:

    //Function to set the course information
    //The course information is set according to the incoming parameters
    //Post condition: course name =cName; courseNo = cNo; courseGrade = grade; courseCredits = credits;
    void setCourseInfo(string cName, string cNo, char grade, int credits);

    //Function to print the course information
    //If bool parameter isGrade is true, the grade is shown, otherwise three stars are printed
    void print(ostream& outp, bool isGrade);

    //Function to return the credit hours
    //The value of the private data member courseCredits is returned
    int getCredits();

    //Function to return the course number
    //Post condition: cNo = courseNo;
    void getCourseNumber(string& cNo);

    //Function to return the grade for the course
    //The value of the private data member courseGrade is returned
    char getGrade();

    bool operator==(const courseType&) const;
    bool operator!=(const courseType&) const;
    bool operator<=(const courseType&) const;
    bool operator<(const courseType&) const;
    bool operator>=(const courseType&) const;
    bool operator>(const courseType&) const;

    //Constructor
    //The object is initialized according to the parameters
    //Post condition: courseName = cName; courseNo = cNo; courseGrade = grade; courseCredits = credits;
    courseType(string cName = "", string cNo = "", char grade = '*', int credits = 0);

private:
    string courseName; //variable to store the course name
    string courseNo;   //variable to store the course number
    char courseGrade;  //variable to store the grade
    int courseCredits; //variable to store the course credits

};

void courseType::setCourseInfo(std::string cName, std::string cNo, char grade, int credits) {
    courseName = cName;
    courseNo = cNo;
    courseGrade = grade;
    courseCredits = credits;
}

void courseType::print(std::ostream &outp, bool isGrade) {
    outp << left;
    outp << setw(8) << courseNo << "   ";
    outp << setw(15) << courseName;
    outp.unsetf(ios::left);
    outp << setw(3) << courseCredits << "   ";

    if (isGrade)
        outp << setw(4) << courseGrade << endl;
    else
        outp << setw(4) << "***" << endl;
}

courseType::courseType(string cName, string cNo, char grade, int credits) {
    setCourseInfo(cName, cNo, grade, credits);
}

int courseType::getCredits() {
    return courseCredits;
}

char courseType::getGrade() {
    return courseGrade;
}

void courseType::getCourseNumber(string &cNo) {
    cNo = courseNo;
}

bool courseType::operator==(const courseType &right) const {
    return (courseNo == right.courseNo);
}

bool courseType::operator!=(const courseType &right) const {
    return (courseNo != right.courseNo);
}

bool courseType::operator<=(const courseType &right) const {
    return (courseNo <= right.courseNo);
}

bool courseType::operator<(const courseType &right) const {
    return (courseNo < right.courseNo);
}

bool courseType::operator>=(const courseType &right) const {
    return (courseNo >= right.courseNo);
}

bool courseType::operator>(const courseType &right) const {
    return (courseNo > right.courseNo);
}


#endif //DATASTRUCTURES_COURSETYPE_H
