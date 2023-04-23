//
// Created by andro on 4/21/2023.
//

#include "Doctor.h"
#include <utility>
#include "Person.h"

void Doctor::setDoctor(string id, string firstName, string secondName) {
    setPerson(std::move(id),std::move(firstName),std::move(secondName));
}


tuple<string, string, string> Doctor::getDoctor() {
    return getPerson();
}

void Doctor::setCourses(vector<shared_ptr<Course>> courses) {
    teachingCourses = std::move(courses);
}



vector<shared_ptr<Course>> Doctor::getCourses() {
    return teachingCourses;
}

Doctor::Doctor() = default;
Doctor::Doctor(string id, string firstName, string secondName):Person(std::move(id), std::move(firstName), std::move(secondName)) {
}
