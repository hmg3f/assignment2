#pragma once
#include <string>

class Employee {
private:
    std::string firstName, lastName;
    
    // position is the employee's current job (manager, software engineer, etc..)
    std::string position;
    
public:
    // these functions are defined in derived classes
    virtual double getWeeklySalary() = 0;
    virtual double getHealthCareContribution() = 0;
    virtual int getVacationDays() = 0;

    std::string getFirstName();
    std::string getLastName();
    std::string getPosition();

    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setPosition(std::string position);

    Employee(std::string firstName, std::string lastName, std::string position);
};
