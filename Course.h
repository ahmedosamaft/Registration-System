//
// Created by andro on 4/21/2023.
//
#include <bits/stdc++.h>



using namespace std;

#ifndef REGISTERATION_SYSTEM_COURSE_H
#define REGISTERATION_SYSTEM_COURSE_H

class Doctor;
class Assignment;
class Student;

class Course {
    string courseID, name;
    shared_ptr<Doctor> teachingDoctor;
    vector<shared_ptr<Student>> registerStudents;
    vector<shared_ptr<Assignment>> assignments;
public:
    void setCourse(string courseID, shared_ptr<Doctor> doctorID, string name);

    void setDoctor(shared_ptr<Doctor> d);

    void setAssignments(vector<shared_ptr<Assignment>> assignments);

    void addAssignment(shared_ptr<Assignment> assignment);

    void addStudent(shared_ptr<Student> students);

    void setStudents(vector<shared_ptr<Student>> students);


    string getName();

    string getID();

    shared_ptr<Doctor> getDoctor();

    vector<shared_ptr<Student>> getStudents();

    vector<shared_ptr<Assignment>> getAssignments();




};


#endif //REGISTERATION_SYSTEM_COURSE_H
