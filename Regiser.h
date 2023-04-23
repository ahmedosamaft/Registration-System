//
// Created by andro on 4/22/2023.
//
#include <bits/stdc++.h>
#include "Student.h"

using namespace std;

#ifndef REGISTERATION_SYSTEM_REGISER_H
#define REGISTERATION_SYSTEM_REGISER_H


void register_() {
    string fName,lName, password, id;
    vector<string> menu = {"Student", "Doctor", "Back"};
    int choice = getChoice(menu);
    cout << "Enter First Name: ";
    cin >> fName;
    cout << "Enter Last Name: ";
    cin >> lName;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Username: ";
    cin >> id;
    if (choice == 1) {
        shared_ptr<Student> std{new Student(id, fName, lName)};
        std->setPassword(password);
        student.push_back(std);
    }
    else if(choice == 2){
        shared_ptr<Doctor> doc{new Doctor(id, fName, lName)};
        doc->setPassword(password);
        doctor.push_back(doc);
    }

}


#endif //REGISTERATION_SYSTEM_REGISER_H
