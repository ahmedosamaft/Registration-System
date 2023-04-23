#include <bits/stdc++.h>
#include "Login.h"
#include "Regiser.h"

using namespace std;

fstream doctors, students, courses;


int main() {
    // =================== Preprocessing ====================
    doctors.open("doctors.txt", (ios::in | ios::out | ios::app));
    students.open("students.txt", (ios::in | ios::out | ios::app));
    courses.open("courses.txt", (ios::in | ios::out | ios::app));
    if (doctors.fail() ||  courses.fail() || students.fail()) {
        closeAll(doctors, courses, students);
        exit(1);
    }
    // ===================================================
    vector<string> menu = {"Login", "Sign up", "Exit"};
    cout << "Date: " << __DATE__ << endl;
    readAll();
    while (true) {
        int choice = getChoice(menu);
        if (choice == 1) {
            login();
        } else if (choice == 2) {
            register_();
        } else
            break;
    }
    closeAll(doctors,courses, students);
}
