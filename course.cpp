#include "course.h"

void Course::setCourseId(string courseId) {
    this->courseId = courseId;
}

void Course::setCourseName(string courseName) {
    this->courseName = courseName;
}

void Course::setCreditHours(int creditHours) {
    this->creditHours = creditHours;
}

string Course::getCourseId() {
    return courseId;
}

string Course::getCourseName() {
    return courseName;
}

int Course::getCreditHours() {
    return creditHours;
}
