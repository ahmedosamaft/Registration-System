#include <bits/stdc++.h>
#include "Student.h"
#include "StudentController.h"
#include "Doctor.h"
#include "Course.h"

using namespace std;
#ifndef REGISTERATION_SYSTEM_LOGIN_H
#define REGISTERATION_SYSTEM_LOGIN_H

void login() {
    auto user = getUser();

    loggedStudent = findInStudents(user);
    loggedDoctor = findInDoctors(user);
    if (!loggedStudent && !loggedDoctor) {
        cout << "User not Found!\n";
        return;
    }
    if(loggedStudent){
        studentController();
    }
}

#endif //REGISTERATION_SYSTEM_LOGIN_H
