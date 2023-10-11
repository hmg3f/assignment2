#include "ProfessionalEmployee.hpp"

double ProfessionalEmployee::getWeeklySalary() {
    return monthly_salary / 4;
}

double ProfessionalEmployee::getHealthCareContribution() {
    return monthly_salary * 0.05;
}

int ProfessionalEmployee::getVacationDays() {
    return vacation_days;
}

ProfessionalEmployee::ProfessionalEmployee(std::string firstName,
					   std::string lastName,
					   std::string position,
					   double monthly_salary,
					   double vacation_days)
    : Employee(firstName, lastName, position)
{
    this->monthly_salary = monthly_salary;
    this->vacation_days = vacation_days;
}

void ProfessionalEmployee::setMonthlySalary(double monthly_salary) {
    this->monthly_salary = monthly_salary;
}

double ProfessionalEmployee::getMonthlySalary() {
    return this->monthly_salary;
}

void ProfessionalEmployee::setAllowedVacationDays(double vacation_days) {
    this->vacation_days = vacation_days;
}
