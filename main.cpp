#include<iostream>
#include"llist.hpp"
#include"Employee.hpp"
#include"ProfessionalEmployee.hpp"
#include"NonprofessionalEmployee.hpp"

int main() {
    SingleLinkedList<int> myList;

    std::cout << "[[[ LINKED LIST TESTS ]]]\n";
    std::cout << "----- empty stack (-1 error code) -----\n";
    std::cout << "back: " << myList.back().value_or(-1) << std::endl;
    std::cout << "front: " << myList.front().value_or(-1) << std::endl;
    std::cout << "pop_back: " << myList.pop_back().value_or(-1) << std::endl;
    std::cout << "pop_front: " << myList.pop_front().value_or(-1) << std::endl;
    std::cout << "\n----- pushing 5 to the back of empty list -----\n";
    myList.push_back(5);
    std::cout << "pop_back: " << myList.pop_back().value_or(-1) << std::endl;
    std::cout << "\n----- pushing 3 to the front of empty list -----\n";
    myList.push_front(3);
    std::cout << "pop_front: " << myList.pop_front().value_or(-1) << std::endl;
    std::cout << "\n----- inserting 10 at position 0 of empty list -----\n";
    myList.insert(0, 10);
    std::cout << "find 10: " << myList.find(10) << std::endl;
    std::cout << "\n----- removing element at position 0 -----\n";
    std::cout << "remove success? (1/0): " << myList.remove(0) << std::endl;
    std::cout << "\n----- inserting/removing at position 1 of empty list (invalid position) -----\n";
    myList.insert(1, 20);
    myList.remove(1);
    std::cout << "\n----- operations on a longer list -----\n";
    myList.push_front(4);
    myList.push_back(3);
    myList.push_front(2);
    myList.push_front(1);
    myList.push_back(6);
    std::cout << "current list: ";
    myList.print_list();
    for (int i = 0; i < 5; i++)
	std::cout << "element at position " << i << ": " << myList.pop_front().value() << std::endl;
    std::cout << "\n----- reverse of previous operations -----\n";
    myList.push_front(4);
    myList.push_back(3);
    myList.push_front(2);
    myList.push_front(1);
    myList.push_back(6);
    std::cout << "current list: ";
    myList.print_list();
    for (int i = 5; i > 0; i--)
	std::cout << "element at position " << i << ": " << myList.pop_back().value() << std::endl;
    std::cout << "\n----- clearing a list -----\n";
    myList.push_front(3);
    myList.push_front(8);
    myList.push_front(2);
    myList.push_front(5);
    std::cout << "current list: ";
    myList.print_list();
    std::cout << "clearning entire list...\n";
    myList.empty();
    std::cout << "current list: ";
    std::cout << std::endl;
    myList.print_list();
    std::cout << "\n----- accessing elements of a list -----\n";
    myList.push_front(2);
    myList.push_front(5);
    myList.push_front(7);
    myList.push_front(2);
    myList.push_front(9);
    std::cout << "current list: ";
    myList.print_list();
    std::cout << "front: " << myList.front().value() << std::endl;
    std::cout << "back: " << myList.back().value() << std::endl;
    std::cout << "\n----- inserting and removing -----\n";
    std::cout << "current list: ";
    myList.print_list();
    std::cout << "inserting 4 at position 3...\n";
    myList.insert(3, 4);
    std::cout << "current list: ";
    myList.print_list();
    std::cout << "removing element at position 2...\n";
    myList.remove(2);
    std::cout << "current list: ";
    myList.print_list();
    std::cout << "\n----- finding elements in the list -----\n";
    myList.push_front(5);
    myList.push_front(7);
    myList.push_front(2);
    std::cout << "current list: ";
    myList.print_list();
    std::cout << "find 4: " << myList.find(4) << std::endl;

    std::cout << "\n\n\n[[[ EMPLOYEE CLASS TESTS ]]]\n";
    ProfessionalEmployee pe1("John", "Smith", "Manager", 9024.20, 14);
    NonprofessionalEmployee ne1("Jane", "Doe", "Contractor", 278, 40, 24.15);

    std::cout << "* For professional employees, monthly salaries and vacation days are pre-determined. Hence, weekly salaries are just 1/4 of the monthly salaries. Their monthly health care contribution is based off their salary.\n* Nonprofessional employees are paid by the hour, their health care contribution is fixed at $300 per month, and their vacation days are 15% of their hours worked rounded up.\n\n";

    std::cout << "Professional Employee:\n";
    std::cout << "Name: " << pe1.getFirstName() << " " << pe1.getLastName() << std::endl;
    std::cout << "Position: " << pe1.getPosition() << std::endl;
    std::cout << "Monthly Salary: " << pe1.getMonthlySalary() << std::endl;
    std::cout << "Weekly Salary: " << pe1.getWeeklySalary() << std::endl;
    std::cout << "Vacation Days Allowed (flat amount): " << pe1.getVacationDays() << std::endl;
    std::cout << "Health Care Contribution: " << pe1.getHealthCareContribution() << std::endl;
    std::cout << "\n";

    std::cout << "Nonprofessional Employee:\n";
    std::cout << "Name: " << ne1.getFirstName() << " " << ne1.getLastName() << std::endl;
    std::cout << "Position: " << ne1.getPosition() << std::endl;
    std::cout << "Hourly Rate: " << ne1.getHourlyRate() << std::endl;
    std::cout << "Hours Worked This Week: " << ne1.getWeeklyHoursWorked() << std::endl;
    std::cout << "Weekly Salary: " << ne1.getWeeklySalary() << std::endl;
    std::cout << "Total Hours Worked: " << ne1.getHoursWorked() << std::endl;
    std::cout << "Vacation Days Allowed: " << ne1.getVacationDays() << std::endl;
    std::cout << "Health Care Contribution: " << ne1.getHealthCareContribution() << std::endl;
    
    return 0;
}
