//
// Created by andro on 4/21/2023.
//
#include <bits/stdc++.h>



using namespace std;

#ifndef REGISTERATION_SYSTEM_COURSE_H
#define REGISTERATION_SYSTEM_COURSE_H

class Doctor;
class Assignment;

class Course {
    string courseID, name;
    shared_ptr<Doctor> teachingDoctor;
    vector<shared_ptr<Assignment>> assignments;
public:
    void setCourse(string courseID, shared_ptr<Doctor> doctorID, string name);

    void setDoctor(shared_ptr<Doctor> d);

    void setAssignments(vector<shared_ptr<Assignment>> assignments);

    void addAssignment(shared_ptr<Assignment> assignment);

    string getName();

    string getID();

    shared_ptr<Doctor> getDoctor();

    vector<shared_ptr<Assignment>> getAssignments();




};


#endif //REGISTERATION_SYSTEM_COURSE_H
