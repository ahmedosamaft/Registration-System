//
// Created by andro on 4/21/2023.
//

#include "Course.h"

void Course::setCourse(string courseID, shared_ptr <Doctor> doctor, string name) {
    this->courseID = courseID;
    this->teachingDoctor = doctor;
    this->name = name;
}

string Course::getName() {
    return name;
}

string Course::getID() {
    return courseID;
}

shared_ptr <Doctor> Course::getDoctor() {
    return teachingDoctor;
}

void Course::setDoctor(shared_ptr <Doctor> d) {
    teachingDoctor = d;
}

void Course::setAssignments(vector<shared_ptr<Assignment>> assignments) {
    this->assignments = assignments;
}

void Course::addAssignment(shared_ptr<Assignment> assignment) {
    this->assignments.push_back(assignment);
}

vector<shared_ptr<Assignment>> Course::getAssignments() {
    return  this->assignments;
}



void Course::setStudents(vector<shared_ptr<Student>> students) {
    this->registerStudents = students;
}

void Course::addStudent(shared_ptr<Student> student) {
    this->registerStudents.push_back(student);
}

vector<shared_ptr<Student>> Course::getStudents() {
    return this->registerStudents;
}






