//
// Created by andro on 4/21/2023.
//
#include <bits/stdc++.h>
#include "Student.h"
#include "Helper.h"
#include "Doctor.h"
#include "Course.h"

using namespace std;
vector<shared_ptr<Course>> unregisteredCourse;
vector<shared_ptr<AssignmentSolution>> assignmentSolutions;
vector<shared_ptr<Student>> student;

void viewCourses();

void gradesReport();

void studentController() {
    cout << "Hello " << loggedStudent->getFullName() << endl;
    vector<string> menu = {"Register in a Course", "View Courses", "Grades Report", "Logout"};
    while (true) {
        int choice = getChoice(menu);
        if (choice == 1) {
            int index = showUnregisteredCourses() - 1;
            if (index == -1) continue;
            auto chosenCourse = unregisteredCourse[index];
            cout << "Registered Successfully!\n";
            loggedStudent->addCourse(chosenCourse);
        } else if (choice == 2) {
            viewCourses();
        } else if (choice == 3) {
            gradesReport();
        } else break;
    }
}


void viewCourses() {
    int index = showRegisteredCourses() - 1;
    if (index == -1) return;
    auto chosenCourse = loggedStudent->getCourse()[index];
    showCourse(chosenCourse);
    vector<string> courseMenu = {"Unregister from Course", "View Assignments", "Back"};
    int subMenu = getChoice(courseMenu);
    if (subMenu == 1) {
        loggedStudent->removeCourse(chosenCourse);
    } else if (subMenu == 2) {
        for (const auto &assign: chosenCourse->getAssignments()) {
            auto answer = assign->checkStudentAnswer(loggedStudent);
            showAnswer(answer, assign);
        }
        vector<string> menu_ = {"Submit a Solution", "Back"};
        int subMenu_ = getChoice(menu_);
        if (subMenu_ == 1) {
            int ind = 0;
            cout << "Choose an Assignment: ";
            cin >> ind;
            if (ind > 0 && ind <= chosenCourse->getAssignments().size()) {
                shared_ptr<AssignmentSolution> sol{new AssignmentSolution()};
                auto chosenAssignment = chosenCourse->getAssignments()[ind - 1];
                cout << "Enter Your Answer Without Spaces: ";
                string s;
                cin >> s;
                sol->setGrade(-1);
                sol->setCourse(chosenCourse);
                sol->setAnswer(s);
                sol->setStudent(loggedStudent);
                sol->setAssignment(chosenAssignment);
                chosenAssignment->addSolution(sol);
                loggedStudent->addAssignmentSolutions(sol);
                assignmentSolutions.push_back(sol);
            }
        }
    } else return;
}


void gradesReport() {
    if (loggedStudent->getAssignmentSolutions().empty()) {
        cout << "No Available Assignment Submissions for you!\n";
    } else
        for (const auto &solution: loggedStudent->getAssignmentSolutions()) {
            cout << "Assignment #" << solution->getAssignment()->getName() << " for Course ["
                 << solution->getCourse()->getName() << "] Grade: "
                 << ((solution->getGrade() == -1) ? "NA" : to_string(solution->getGrade())) << " / "
                 << solution->getAssignment()->getMaxGrade() << " Submitted Answer: " << solution->getAnswer() << endl;
        }
}