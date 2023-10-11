#include "NonprofessionalEmployee.hpp"
#include <math.h>

double NonprofessionalEmployee::getWeeklySalary() {
    return  weekly_hours_worked * 5 * hourly_rate;
}

double NonprofessionalEmployee::getHealthCareContribution() {
    return 300;
}

int NonprofessionalEmployee::getVacationDays() {
    return ceil((hours_worked * 0.15) / 24.0);
}

NonprofessionalEmployee::NonprofessionalEmployee(std::string firstName,
						 std::string lastName,
						 std::string position,
						 int hours_worked,
						 int weekly_hours_worked,
						 double hourly_rate)
    : Employee(firstName, lastName, position)
{
    this->hours_worked = hours_worked;
    this->weekly_hours_worked = weekly_hours_worked;
    this->hourly_rate = hourly_rate;
}

void NonprofessionalEmployee::setHoursWorked(int hours_worked) {
    this->hours_worked = hours_worked;
}

int NonprofessionalEmployee::getHoursWorked() {
    return this->hours_worked;
}

void NonprofessionalEmployee::setWeeklyHoursWorked(int weekly_hours_worked) {
    this->weekly_hours_worked = weekly_hours_worked;
}

int NonprofessionalEmployee::getWeeklyHoursWorked() {
    return this->weekly_hours_worked;
}


void NonprofessionalEmployee::setHourlyRate(double hourly_rate) {
    this->hourly_rate = hourly_rate;
}

double NonprofessionalEmployee::getHourlyRate() {
    return this->hourly_rate;
}
