//
// Created by andro on 4/22/2023.
//

#include "Assignment.h"

void Assignment::setAssignment(string name, int maxGrade, shared_ptr<Course> course) {
    this->content = name;
    this->grade = maxGrade;
    this->course_ = course;
}


void Assignment::addSolution(shared_ptr<AssignmentSolution> assignment) {
    this->assignmentSolution.push_back(assignment);
}

int Assignment::getMaxGrade() {
    return grade;
}

string Assignment::getName() {
    return content;
}

shared_ptr<Course> Assignment::getCourse() {
    return course_;
}

vector<shared_ptr<AssignmentSolution>> Assignment::getSolutions() {
    return assignmentSolution;
}

void Assignment::setSolutions(vector <shared_ptr<AssignmentSolution>> assignment) {
    this->assignmentSolution = assignment;
}

shared_ptr<AssignmentSolution> Assignment::checkStudentAnswer(shared_ptr<Student> student_) {
    for (const auto &solution: assignmentSolution) {
        if(solution->getStudent() == student_){
            return solution;
        }
    }
    return nullptr;
}

