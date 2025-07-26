#include "studentmanager.h"
#include "student.h"
#include <iostream>

using namespace std;

StudentManager::StudentManager() {
    studentCount = 0;
}

bool StudentManager::addNewStudent(Student& student) {
    if (studentCount >= 100)
        return false;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getid() == student.getid())
            return false;
    }

    students[studentCount++] = student;
    return true;
}

Student* StudentManager::findStudentById(string& id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getid() == id)
            return &students[i];
    }
    return nullptr;
}

bool StudentManager::removeStudentById(string& id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getid() == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            return true;
        }
    }
    return false;
}

void StudentManager::showAllStudents() {
    if (studentCount == 0) {
        cout << "No students found.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        cout << "-----------------------\n";
        students[i].showStudentInfo();
    }
}

int StudentManager::getStudentCount() {
    return studentCount;
}
