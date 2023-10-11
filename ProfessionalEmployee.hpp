#pragma once
#include "Employee.hpp"

class ProfessionalEmployee : public Employee {
private:
    // the monthly salary the employee should be payed (fixed amount)
    double monthly_salary;

    // the number of vacation days the employee is allowed (fixed amount)
    int vacation_days;
public:
    // pre: monthly salary
    // post: return monthly salary / 4
    double getWeeklySalary();

    // pre: monthly salary
    // post: return health care contribution based on salary
    double getHealthCareContribution();

    // pre: vacation days
    // post: return number of allowed vacation days (fixed amount)
    int getVacationDays();

    ProfessionalEmployee(std::string first, std::string last, std::string pos, double monthly_salary, double vacation_days);

    void setMonthlySalary(double);
    double getMonthlySalary();

    void setAllowedVacationDays(double);
};
