//
// Created by andro on 4/22/2023.
//

#include "Person.h"

#include <utility>

Person::Person(string userName, string firstName, string secondName) : userName(std::move(userName)), firstName(std::move(firstName)),
                                                                       secondName(std::move(secondName)) {}

Person::Person() = default;

tuple<string, string, string> Person::getPerson() {
    return {userName, firstName, secondName};
}

string Person::getFullName() {
    return firstName + " " + secondName;
}

string Person::getID() {
    return userName;
}

void Person::setPerson(string id, string fName, string sName) {
    this->userName = std::move(id);
    this->firstName = std::move(fName);
    this->secondName = std::move(sName);
}

void Person::setPassword(string password) {
    this->password = password;
}

bool Person::checkPerson(pair<string, string> user) {
   return (user.first == this->userName && user.second == this->password);
}
