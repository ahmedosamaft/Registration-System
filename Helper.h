//
// Created by andro on 4/21/2023.
//

#include <bits/stdc++.h>
#include "Course.h"
#include "Doctor.h"
#include "Student.h"
#include "Assignment.h"

#ifndef REGISTERATION_SYSTEM_HELPER_H
#define REGISTERATION_SYSTEM_HELPER_H
using namespace std;


vector<shared_ptr<Doctor>> doctor;
vector<shared_ptr<Course>> course;
vector<shared_ptr<Assignment>> assignments;
extern vector<shared_ptr<Student>> student;
extern fstream doctors, students, courses;
extern vector<shared_ptr<Course>> unregisteredCourse;
extern vector<shared_ptr<Student>> student;

shared_ptr<Student> loggedStudent;
shared_ptr<Doctor> loggedDoctor;

// *** Show Menu ***
int getChoice(vector<string> &menu) {
    cout << "Please make a choice:\n";
    for (int i = 0; i < menu.size(); ++i) {
        cout << i + 1 << " - " << menu[i] << endl;
    }
    cout << "Choice: ";
    int choose;
    cin >> choose;
    return choose;
}

// *** Close all Files ***
void closeAll() {
}

template<typename... t>
void closeAll(fstream &input, t &... files) {
    input.close();
    closeAll(files...);
}

// *** Split Line and return Vector ***
vector<string> split(string &line) {
    line += ' ';
    string word;
    vector<string> splited;
    for (int i = 1; i < line.size(); ++i) {
        if (line[i] == ' ') {
            splited.push_back(word);
            word = "";
        } else word += line[i];
    }
    return splited;
}


vector<shared_ptr<Course>> getListedCourse(string l) {
    auto allID = split(l);
    vector<shared_ptr<Course>> ans;
    for (const auto &i: allID) {
        for (auto &c: course) {
            if (c->getID() == i) {
                ans.push_back(c);
            }
        }
    }

    return ans;
}


shared_ptr<Student> findInStudents(pair<string, string> user) {
    for (const auto &s_: student)
        if (s_->checkPerson(user))
            return s_;
    return nullptr;
}

shared_ptr<Doctor> findInDoctors(pair<string, string> user) {
    for (const auto &d_: doctor)
        if (d_->checkPerson(user))
            return d_;
    return nullptr;
}


void readDoctors() {
    string id, fName, sName, line;
    while (doctors >> id >> fName >> sName, getline(doctors, line)) {
        shared_ptr<Doctor> d{new Doctor(id, fName, sName)};
        d->setCourses(getListedCourse(line));
        d->setPassword(id);
        doctor.push_back(d);
    }

}


void readCourses() {
    string courseID, doctorID, line;
    while (courses >> courseID >> doctorID, getline(courses, line)) {
        shared_ptr<Course> c{new Course()};
        shared_ptr<Doctor> choosenD;
        for (auto &d: doctor) {
            if (d->getID() == doctorID) {
                choosenD = d;
                break;
            }
        }
        c->setCourse(courseID, choosenD, line.substr(1));
        course.push_back(c);
    }
}


void readStudents() {
    string id, fName, sName, line;
    while (students >> id >> fName >> sName, getline(students, line)) {
        shared_ptr<Student> s{new Student(id, fName, sName)};
        s->setPassword(id);
        for (const auto &courseId: split(line)) {
            for (const auto &course_: course) {
                if (course_->getID() == courseId) {
                    s->addCourse(course_);
                    break;
                }
            }
        }
        student.push_back(s);
    }

}


void assignDoctorsToCourses() {
    for (const auto &d: doctor) {
        for (auto &Cours: d->getCourses()) {
            Cours->setDoctor(d);
        }
    }
}

pair<string, string> getUser() {
    pair<string, string> u;
    cout << "Username: ";
    cin >> u.first;
    cout << "Password: ";
    cin >> u.second;

    return u;
}

int randomNum(int l, int r) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}

void generateDummyAssignments() {
    for (const auto &course_: course) {
        int range = randomNum(1, 10);
        for (int i = 0; i < range; ++i) {
            shared_ptr<Assignment> newAssign{new Assignment()};
            newAssign->setAssignment(to_string(i + 1), randomNum(10, 100), course_);
            assignments.push_back(newAssign);
            course_->addAssignment(newAssign);
        }
    }
}


/* First: Check that Student is Registered in This course
 * second: Add Assignment
 *
 * */


auto assignStudentToCourses = []() {
    for (const auto &std: student) {
        for (const auto &course_: std->getCourse()) {
            course_->addStudent(std);
        }
    }
};

void readAll() {
    readCourses();
    readDoctors();
    assignDoctorsToCourses();
    readStudents();
    generateDummyAssignments();
    assignStudentToCourses();
}

void showCourse(shared_ptr<Course> chosenCourse) {
    cout << "Course Details " << chosenCourse->getName() << " with Code "
         << chosenCourse->getID() << " - taught by Dr."
         << chosenCourse->getDoctor()->getFullName() << endl;
}

void showAnswer(shared_ptr<AssignmentSolution> answer, shared_ptr<Assignment> assign) {
    if (answer != nullptr && answer->getGrade() == -1) {
        cout << "Assignment #" << assign->getName() << " - Waiting for Doctor to give you grade" << endl;
    } else
        cout << "Assignment #" << assign->getName() << " - Grade: "
             << ((answer == nullptr) ? "NA" : to_string(answer->getGrade())) << " / "
             << assign->getMaxGrade()
             << endl;
}


// Display all Courses that Student enrolled in
int showRegisteredCourses() {
    int counter = 0;
    if (loggedStudent->getCourse().empty()) {
        cout << "There aren't any Courses available!\n";
        return 0;
    }
    for (auto &c: loggedStudent->getCourse()) {
        cout << ++counter << ") ";
        showCourse(c);
    }
    int choice = 0;
    cout << "Choose Course to show details: ";
    cin >> choice;
    return choice;
}


//show unregistered Courses
int showUnregisteredCourses() {
    unregisteredCourse = loggedStudent->getUnregisteredCourse();
    int counter = 0;
    if (unregisteredCourse.empty()) {
        cout << "There isn't any Courses available!\n";
        return 0;
    }
    for (auto &c: unregisteredCourse) {
        cout << ++counter << " - Course " << c->getName() << " with Code " << c->getID() << endl;
    }
    int choice = 0;
    cout << "choose course to register in: ";
    cin >> choice;
    return choice;
}


void DoctorViewCourse() {
    int co = 1;
    for (const auto &cours: loggedDoctor->getCourses()) {
        cout << co++ << ") Course Name: " << cours->getName()
             << " - Code: " << cours->getID() << " Total Students: " << cours->getStudents().size() << endl;
    }
}

void DoctorViewDetails(shared_ptr<Course> cours) {
    int c = 1;
    cout << "- Registered Students:\n";
    for (const auto &std: cours->getStudents()) {
        cout << "\t" << c++ << ") ID: " << std->getID() << " Name: " << std->getFullName() << "\n";
    }
    cout << "- Assignments:\n";c = 1;
    for (const auto &std: cours->getAssignments()) {
        cout << "\t" << c++ << ") Assignment #" << std->getName() << " | Max Grade: " << std->getMaxGrade()
             << " | Total Solutions: " << std->getSolutions().size() << "\n";
    }
}

#endif //REGISTERATION_SYSTEM_HELPER_H
