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
vector<shared_ptr<Student>> student;

// Read all Students From file { User, First Name, Second Name, Courses }


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
            int index = showRegisteredCourses() - 1;
            if (index == -1) continue;
            auto chosenCourse = loggedStudent->getCourse()[index];
            showCourse(chosenCourse);
            vector<string> courseMenu = {"Unregister from Course", "View Assignments", "Back"};
            int subMenu = getChoice(courseMenu);
            if (subMenu == 1) {
                loggedStudent->removeCourse(chosenCourse);
            } else {
                for (const auto &assign: chosenCourse->getAssignments()) {
                    auto answer = assign->checkStudentAnswer(loggedStudent);
                    showAnswer(answer, assign);
                }
                vector<string> menu_ = {"Submit a Solution", "Back"};
                int subMenu_ = getChoice(menu_);
                if (subMenu_ == 1){
                    int ind = 0;
                    cout << "Choose an Assignment: ";
                    cin >> ind;
                    if(ind > 0 && ind <= chosenCourse->getAssignments().size()){
                        shared_ptr<AssignmentSolution> sol{new AssignmentSolution()};
                        auto chosenAssignment = chosenCourse->getAssignments()[ind - 1];
                        cout << "Enter Your Answer Without Spaces: ";
                        string s;
                        cin >> s;
                        sol->setGrade(-1);
                        sol->setAnswer(s);
                        sol->setStudent(loggedStudent);
                        sol->setAssignment(chosenAssignment);
                        chosenAssignment ->addSolution(sol);
                    }
                }


            }
        } else break;
    }
}





