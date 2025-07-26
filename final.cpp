#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "studentmanager.h"
#include "course.h"
#include "student.h"

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    StudentManager manager;
    int choice;
    string id, name, password, course;

    ifstream inFile("students.txt");
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string id, name, password;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, password, ',');

        Student s;
        s.setid(id);
        s.setname(name);
        s.setpassword(password);

        manager.addNewStudent(s);
    }
    inFile.close();

    while (true)
    {
        SetConsoleTextAttribute(hConsole, 11); 
        cout << "\n====== School Management System ======\n";
        cout << "1 - Add Student: " << "\n";
        cout << "2 - Enroll in Course: " << "\n";
        cout << "3 - Remove Course: " << "\n";
        cout << "4 - Show Student info: " << "\n";
        cout << "5 - Delete Student: " << "\n";
        cout << "6 - Exit: " << "\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Student ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter Password: ";
            cin >> password;

            {
                Student newStudent;
                newStudent.setid(id);
                newStudent.setname(name);
                newStudent.setpassword(password);

                if (manager.addNewStudent(newStudent)) {
                    SetConsoleTextAttribute(hConsole, 10); 
                    cout << "Student added successfully.\n";

                    ofstream outFile("students.txt", ios::app);
                    if (outFile.is_open()) {
                        outFile << id << "," << name << "," << password << "\n";
                        outFile.close();
                    } else {
                        SetConsoleTextAttribute(hConsole, 12); 
                        cout << "Error: Couldn't write to file.\n";
                    }

                } else {
                    SetConsoleTextAttribute(hConsole, 12); 
                    cout << "Failed to add student (maybe already exists).\n";
                }
            }
            break;

        case 2:
            cout << "Enter Student ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Course Name: ";
            getline(cin, course);

            {
                Student* student = manager.findStudentById(id);
                if (student) {
                    if (student->addCourse(course)) {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Course enrolled successfully.\n";
                    } else {
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Failed to enroll (maybe already enrolled or limit reached).\n";
                    }
                }
                else {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Student not found.\n";
                }
            }
            break;

        case 3:
            cout << "Enter Student ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Course Name to remove: ";
            getline(cin, course);

            {
                Student* student = manager.findStudentById(id);
                if (student) {
                    if (student->removeCourse(course)) {
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << "Course removed successfully.\n";
                    } else {
                        SetConsoleTextAttribute(hConsole, 12);
                        cout << "Failed to remove course (not enrolled).\n";
                    }
                }
                else {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Student not found.\n";
                }
            }
            break;

        case 4:
            cout << "Enter Student ID to display info: ";
            cin >> id;

            {
                Student* student = manager.findStudentById(id);
                if (student) {
                    SetConsoleTextAttribute(hConsole, 14);
                    student->showStudentInfo();
                }
                else {
                    SetConsoleTextAttribute(hConsole, 12);
                    cout << "Student not found.\n";
                }
            }
            break;

        case 5:
            cout << "Enter Student ID to Delete: ";
            cin >> id;

            if (manager.removeStudentById(id)) {
                SetConsoleTextAttribute(hConsole, 10);
                cout << "Student deleted successfully.\n";


            } else {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Student Not Found.\n";
            }
            break;

        case 6:
            SetConsoleTextAttribute(hConsole, 11);
            cout << "Exiting program. Goodbye!\n";
            return 0;

        default:
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Invalid choice. Try again.\n";
        }
    }
}
