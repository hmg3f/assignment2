#pragma once
#include "Employee.hpp"

class NonprofessionalEmployee : public Employee {
    // the total amount of hours worked by the employee
    int hours_worked;

    // the amount of hours worked this week by the employee
    int weekly_hours_worked;

    // the hourly rate of the employee
    double hourly_rate;
public:
    // pre: hourly rate and amount of hours worked this week
    // post: return the product of the two inputs
    double getWeeklySalary();

    // pre: nothing
    // post: return 300 (fixed contribution)
    double getHealthCareContribution();

    // pre: total number of hours worked
    // post: return number of vacation days allowed (rounded up)
    int getVacationDays();

    NonprofessionalEmployee(std::string first, std::string last, std::string pos, int hours_worked, int weekly_hours_worked, double hourly_rate);

    int getHoursWorked();
    void setHoursWorked(int);

    int getWeeklyHoursWorked();
    void setWeeklyHoursWorked(int);

    double getHourlyRate();
    void setHourlyRate(double);
};
