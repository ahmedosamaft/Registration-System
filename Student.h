
#include <bits/stdc++.h>
#include "Course.h"
#include "Person.h"
#include "AssignmentSolution.h"

using namespace std;
#ifndef REGISTERATION_SYSTEM_STUDENT_H
#define REGISTERATION_SYSTEM_STUDENT_H


class Student: public Person {
    vector<shared_ptr<Course>> registeredCourses;
    vector<shared_ptr<AssignmentSolution>> assignmentSolution;
public:
    Student(string id, string firstName, string secondName);
    Student();
    void setAssignmentSolutions (vector<shared_ptr<AssignmentSolution>> assignments);
    void addAssignmentSolutions (shared_ptr<AssignmentSolution> assignment);
    void addCourse(const shared_ptr<Course>& course);
    void removeCourse(shared_ptr<Course> course);
    vector<shared_ptr<Course>> getCourse();
    vector<shared_ptr<Course>> getUnregisteredCourse();
    vector<shared_ptr<AssignmentSolution>> getAssignmentSolutions();
};


#endif //REGISTERATION_SYSTEM_STUDENT_H
