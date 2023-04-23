//
// Created by andro on 4/22/2023.
//
#include <bits/stdc++.h>
#include "AssignmentSolution.h"
#include "Course.h"

#ifndef REGISTERATION_SYSTEM_ASSIGNMENT_H
#define REGISTERATION_SYSTEM_ASSIGNMENT_H


using namespace std;

class Assignment {
    string content;
    int grade;
    shared_ptr<Course> course_;
    vector<shared_ptr<AssignmentSolution>> assignmentSolution;
public:
    void setAssignment(string name, int maxGrade, shared_ptr<Course> course);

    void setSolutions(vector<shared_ptr<AssignmentSolution>> assignment);

    void addSolution(shared_ptr<AssignmentSolution> assignment);

    int getMaxGrade();

    string getName();

    shared_ptr<Course> getCourse();


    shared_ptr<AssignmentSolution> checkStudentAnswer(shared_ptr<Student> student_);

    vector<shared_ptr<AssignmentSolution>> getSolutions();
};

#endif //REGISTERATION_SYSTEM_ASSGINMENT_H
