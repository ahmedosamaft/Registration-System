//
// Created by andro on 4/21/2023.
//
#include <bits/stdc++.h>
#include "Course.h"
#include "Person.h"

using namespace std;

#ifndef REGISTERATION_SYSTEM_DOCTOR_H
#define REGISTERATION_SYSTEM_DOCTOR_H


class Doctor : public Person {
    vector<shared_ptr<Course>> teachingCourses;
public:
    void setDoctor(string id, string firstName, string secondName);
    Doctor();
    Doctor(string id, string firstName, string secondName);
    void setCourses(vector<shared_ptr<Course>> courses);
    tuple<string, string, string> getDoctor();
    vector<shared_ptr<Course>> getCourses();
};


#endif //REGISTERATION_SYSTEM_DOCTOR_H
