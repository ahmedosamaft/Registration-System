//
// Created by andro on 4/22/2023.
//
#include <bits/stdc++.h>
#include "Course.h"

using namespace std;
#ifndef REGISTERATION_SYSTEM_ASSIGNMENTSOLUTION_H
#define REGISTERATION_SYSTEM_ASSIGNMENTSOLUTION_H

class Assignment;
class Student;

class AssignmentSolution {
    int grade;
    string answer;
    shared_ptr<Assignment> assignment;
    shared_ptr<Course> course_;
    shared_ptr<Student> student_;
public:
    void setGrade(int grade);

    void setCourse(shared_ptr<Course> course_);

    void setAnswer(string answer);

    void setAssignment(shared_ptr<Assignment> assignment);

    void setStudent(shared_ptr<Student> student);

    int getGrade() const;

    string getAnswer();

    shared_ptr<Course> getCourse();

    shared_ptr<Assignment> getAssignment();

    shared_ptr<Student> getStudent();
};


#endif //REGISTERATION_SYSTEM_ASSGINMENTSOLUTION_H
