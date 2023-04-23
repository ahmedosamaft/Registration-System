//
// Created by andro on 4/21/2023.
//

#include "Student.h"

#include <utility>

extern vector<shared_ptr<Course>> course;





vector<shared_ptr<Course>> Student::getCourse() {
    return registeredCourses;
}

void Student::addCourse(const shared_ptr<Course>& course_) {
    registeredCourses.push_back(course_);
}

void Student::removeCourse(shared_ptr<Course> course_) {
    vector<shared_ptr<Course>> tmp;
    for (auto &i: registeredCourses) {
        if(i != course_)
            tmp.push_back(i);
    }

    registeredCourses = tmp;
}

vector<shared_ptr<Course>> Student::getUnregisteredCourse() {
    vector<shared_ptr<Course>> unregisteredCourse;
    unordered_set<shared_ptr<Course>> registered(registeredCourses.begin(),registeredCourses.end());
    for (auto &course_: course) {
        if(registered.find(course_) == registered.end())
            unregisteredCourse.push_back(course_);
    }
    return unregisteredCourse;
}

Student::Student(string id, string firstName, string secondName) : Person(id, firstName, secondName) {

}

void Student::setAssignments(vector<shared_ptr<Assignment>> assignments) {
    this->assignments = assignments;
}

vector<shared_ptr<Assignment>> Student::getAssignments() {
    return this->assignments;
}

void Student::addAssignment(shared_ptr<Assignment> assignment) {
    this->assignments.push_back(assignment);
}



Student::Student() = default;
