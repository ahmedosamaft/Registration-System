
#include <bits/stdc++.h>

using namespace std;
#ifndef REGISTERATION_SYSTEM_PERSON_H
#define REGISTERATION_SYSTEM_PERSON_H



class Person {
    string userName, firstName, secondName,password;
public:
    Person();
    Person(string userName,string firstName,string secondName);
    void setPassword(string password);
    void setPerson(string id, string fName, string sName);
    tuple<string, string, string> getPerson();
    string getID();
    string getFullName();
    bool checkPerson(pair<string, string> user);
};


#endif //REGISTERATION_SYSTEM_PERSONX_H

