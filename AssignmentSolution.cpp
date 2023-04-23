//
// Created by andro on 4/22/2023.
//

#include "AssignmentSolution.h"

#include <utility>

void AssignmentSolution::setGrade(int grade) {
    this->grade = grade;
}

void AssignmentSolution::setAnswer(std::string answer) {
    this->answer = std::move(answer);
}

void AssignmentSolution::setStudent(shared_ptr<Student> student) {
    this->student_ = std::move(student);
}
void AssignmentSolution::setAssignment(shared_ptr<Assignment> assignment) {
    this->assignment = assignment;
}

int AssignmentSolution::getGrade() const {
    return grade;
}

string AssignmentSolution::getAnswer() {
    return answer;
}

shared_ptr<Student> AssignmentSolution::getStudent() {
    return student_;
}

shared_ptr<Assignment> AssignmentSolution::getAssignment() {
    return this->assignment ;
}
