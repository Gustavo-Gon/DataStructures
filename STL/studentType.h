

#ifndef DATASTRUCTURES_STUDENTTYPE_H
#define DATASTRUCTURES_STUDENTTYPE_H

#include <string>
#include <iostream>
#include <vector>
#include "courseType.h"
using namespace std;

class studentType: public personType {
public:

    //Function to set the student's information
    //The private data members are set according to the parameters
    void setInfo(string fname, string lName, int ID, bool isTPaid, vector<courseType> courses);

    //Function to print the student's grade report
    //The outcome is stored in a file specified by the parameter out.
    void print(ostream& out, double tuitionRate);

    //Default constructor
    //Post condition: Data members are initialized to the default values
    studentType();

    //Function to return credit hours a student is enrolled in
    //Post condition: The number of credit hours in which a student is enrolled is calculated and returned
    int getHoursEnrolled();

    //Function to return the grade point average
    //Post condition: The GPA is calculated and returned
    double getGPA();

    //Function to return the tuition fees
    //Post condition: The tuition fees due is calculated and returned

private:
    int sIDd;            //variable to store the student ID
    int numberOfCourses; //variable to store the number od courses
    bool isTuitionPaid;  //variable to indicate if the tuition is paid
    vector<courseType> coursesEnrolled; //vector to store courses

};




#endif //DATASTRUCTURES_STUDENTTYPE_H
