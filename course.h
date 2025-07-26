#pragma once
#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
private:
    string courseId;
    string courseName;
    int creditHours;

public:
    void setCourseId(string courseId);
    void setCourseName(string courseName);
    void setCreditHours(int creditHours);

    string getCourseId();
    string getCourseName();
    int getCreditHours();
};

#endif 
