#include "Employee.hpp"

std::string Employee::getFirstName() {
    return firstName;
}
std::string Employee::getLastName() {
    return lastName;
}
std::string Employee::getPosition() {
    return position;
}

void Employee::setFirstName(std::string firstName) {
    this->firstName = firstName;
}
void Employee::setLastName(std::string lastName) {
    this->lastName = lastName;
}
void Employee::setPosition(std::string position) {
    this->position = position;
}

Employee::Employee(std::string firstName, std::string lastName, std::string position) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->position = position;
}
