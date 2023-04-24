//
// Created by andro on 4/23/2023.
//
#include <bits/stdc++.h>

using namespace std;

#ifndef REGISTERATION_SYSTEM_DOCTORCONTROLLER_H
#define REGISTERATION_SYSTEM_DOCTORCONTROLLER_H

void doctorController() {
    cout << "Hello dr. " << loggedDoctor->getFullName() << endl;
    vector<string> menu = {"View your Courses", "Logout"};
    while (true) {
        int choice = getChoice(menu);
        if (choice == 1) {
            DoctorViewCourse();
            cout << "Choose Course to see details: ";
            int ind = 0;
            cin >> ind;
            if (ind < 1 || ind > loggedDoctor->getCourses().size())
                break;
            auto choseCourse_ = loggedDoctor->getCourses()[ind - 1];
            DoctorViewDetails(choseCourse_);
            vector<string> sub_menu = {"View Assignment Solution", "back"};
            ind = getChoice(sub_menu);
            if (ind != 1) continue;
            cout << "Choose Assignment: ";
            cin >> ind;
            auto chosenAssign = choseCourse_->getAssignments()[ind - 1];
            ind = 1;
            for (const auto &solution: chosenAssign->getSolutions()) {
                cout << '\t' << ind++ << ") Student ID: " << solution->getStudent()->getID() << " | Student Name: "
                     << solution->getStudent()->getFullName() << " | Answer: "
                     << solution->getAnswer() << " | Grade: "
                     << (solution->getGrade() != -1 ? to_string(solution->getGrade()) : "Not Marked Yet") << endl;
            }
            sub_menu = {"Give Grade", "back"};
            ind = getChoice(sub_menu);
            if (ind != 1) continue;
            cout << "Choose Student: ";
            cin >> ind;
            if (ind < 1 || ind > chosenAssign->getSolutions().size()) continue;
            auto chosenStudent = chosenAssign->getSolutions()[ind - 1];
            cout << "Student Details:\n" << "\t ID: " << chosenStudent->getStudent()->getID() << " | Name: "
                 << chosenStudent->getStudent()->getFullName() << " | Answer: " << chosenStudent->getAnswer()
                 << "\nGive Grade out of " << chosenStudent->getAssignment()->getMaxGrade() << ": ";
            cin >> ind;
            if(ind < 0 || ind > chosenStudent->getAssignment()->getMaxGrade())
            {
                cout << "Grade is Not Correct!!";
                break;
            }
            chosenStudent->setGrade(ind);
        } else break;
    }
}

#endif //REGISTERATION_SYSTEM_DOCTORCONTROLLER_H
