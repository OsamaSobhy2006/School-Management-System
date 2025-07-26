#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string studentId;
    string studentName;
    string password;
    string enrollmentDate;
    string courses[5];
    int courseCount;

    string getCurrentDate();

public:
    Student();

    void setid(string studentId);
    string getid();

    void setname(string studentName);
    string getname();

    void setpassword(string password);
    string getpassword();

    string getEnrollmentDate();

    int getCourseCount();
    string getCourse(int index);

    bool addCourse(string courseName);
    bool removeCourse(string courseName);

    void showStudentInfo();
};

#endif 
