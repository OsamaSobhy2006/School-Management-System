#include <iostream>
#include <string>
#include <windows.h>

#include "studentmanager.h"
#include "course.h"
#include "student.h"
#include "authmanager.h"
#include "user.h"

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    AuthManager auth;
    StudentManager manager;

    int loginChoice;
    string id, password;

    bool isLoggedIn = false;

    while (!isLoggedIn) {
        SetConsoleTextAttribute(hConsole, 11);
        cout << "\n====== Authentication ======\n";
        cout << "1 - Register\n";
        cout << "2 - Login\n";
        cout << "Choose: ";
        cin >> loginChoice;

        cout << "Enter Student ID: ";
        cin >> id;

        cout << "Enter Password: ";
        cin >> password;

        if (loginChoice == 1) {
            if (auth.registerUser(id, password)) {
                SetConsoleTextAttribute(hConsole, 10);
                cout << "Registration successful. You can now login.\n";
            }
        } else if (loginChoice == 2) {
            if (auth.loginUser(id, password)) {
                SetConsoleTextAttribute(hConsole, 10);
                cout << "Login successful.\n";
                isLoggedIn = true;
            } else {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Invalid credentials. Try again.\n";
            }
        }
    }

    int choice;
    string name, course;

    while (true)
    {
        SetConsoleTextAttribute(hConsole, 11);
        cout << "\n====== School Management System ======\n";
        cout << "1 - Add Student\n";
        cout << "2 - Enroll in Course\n";
        cout << "3 - Remove Course\n";
        cout << "4 - Show Student info\n";
        cout << "5 - Delete Student\n";
        cout << "6 - Exit\n";
        cout << "Choose: ";
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
