//
// Created by andro on 4/21/2023.
//

#include "Student.h"

#include <utility>

extern vector<shared_ptr<Course>> course;
extern vector<shared_ptr<AssignmentSolution>> assignmentSolutions;


vector<shared_ptr<Course>> Student::getCourse() {
    return registeredCourses;
}

void Student::addCourse(const shared_ptr<Course> &course_) {
    registeredCourses.push_back(course_);
}

void Student::removeCourse(shared_ptr<Course> course_) {
    vector<shared_ptr<Course>> tmp;
    for (auto &i: registeredCourses) {
        if (i != course_)
            tmp.push_back(i);
    }
    vector<shared_ptr<AssignmentSolution>> newAnswers;
    for (auto &sol: this->assignmentSolution) {
        if (sol->getCourse() != course_)
            newAnswers.push_back(sol);
        else{
            sol->setStudent(nullptr);
        }
    }

    registeredCourses = tmp;
    assignmentSolution = newAnswers;
}

vector<shared_ptr<Course>> Student::getUnregisteredCourse() {
    vector<shared_ptr<Course>> unregisteredCourse;
    unordered_set<shared_ptr<Course>> registered(registeredCourses.begin(), registeredCourses.end());
    for (auto &course_: course) {
        if (registered.find(course_) == registered.end())
            unregisteredCourse.push_back(course_);
    }
    return unregisteredCourse;
}

Student::Student(string id, string firstName, string secondName) : Person(id, firstName, secondName) {

}

void Student::setAssignmentSolutions(vector<shared_ptr<AssignmentSolution>> assignments) {
    this->assignmentSolution = assignments;
}

void Student::addAssignmentSolutions(shared_ptr<AssignmentSolution> assignment) {
    this->assignmentSolution.push_back(assignment);
}

vector<shared_ptr<AssignmentSolution>> Student::getAssignmentSolutions() {
    return this->assignmentSolution;
}


Student::Student() = default;
