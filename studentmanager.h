#pragma once
#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <string>
#include "student.h"
using namespace std;

class StudentManager {
private:
    Student students[100];
    int studentCount;

public:
    StudentManager();

    bool addNewStudent(Student& student);
    Student* findStudentById(string& id);
    bool removeStudentById(string& id);
    void showAllStudents();
    int getStudentCount();
};

#endif 
