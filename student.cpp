#include "student.h"
#include <iostream>
#include <ctime>

using namespace std;

Student::Student() {
    courseCount = 0;
    enrollmentDate = getCurrentDate();
}

void Student::setid(string studentId) {
    this->studentId = studentId;
}

string Student::getid() {
    return studentId;
}

void Student::setname(string studentName) {
    this->studentName = studentName;
}

string Student::getname() {
    return studentName;
}

void Student::setpassword(string password) {
    this->password = password;
}

string Student::getpassword() {
    return password;
}

string Student::getEnrollmentDate() {
    return enrollmentDate;
}

int Student::getCourseCount() {
    return courseCount;
}

string Student::getCourse(int index) {
    if (index >= 0 && index < courseCount)
        return courses[index];
    return "";
}

bool Student::addCourse(string courseName) {
    if (courseCount >= 5)
        return false;

    for (int i = 0; i < courseCount; i++) {
        if (courses[i] == courseName)
            return false;
    }

    courses[courseCount++] = courseName;
    return true;
}

bool Student::removeCourse(string courseName) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i] == courseName) {
            for (int j = i; j < courseCount - 1; j++) {
                courses[j] = courses[j + 1];
            }
            courseCount--;
            return true;
        }
    }
    return false;
}

void Student::showStudentInfo() {
    cout << "ID: " << studentId << "\n";
    cout << "Name: " << studentName << "\n";
    cout << "Enrollment Date: " << enrollmentDate << "\n";
    cout << "Courses Enrolled:\n";

    if (courseCount == 0)
        cout << "- None\n";
    else {
        for (int i = 0; i < courseCount; i++)
            cout << "- " << courses[i] << "\n";
    }
}

string Student::getCurrentDate() {
    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back();
    return dt;
}