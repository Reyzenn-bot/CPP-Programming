#include"employee.h"
#include<string>
Employee* inputEmployee() {
    int id;
    string name, type;
    cout<<"Enter id: ";
    cin >> id;
    cin.ignore(100,'\n');
    cout<<"Enter name: ";
    getline(cin,name);
    cout<<"Enter type (FullTime, PartTime, Internship): ";
    getline(cin,type);
    if(type=="FullTime") {
        double salary, bonus;
        cout<<"Enter BaseSalary: ";
        cin >> salary;
        cout<<"Enter Bonus: ";
        cin >> bonus;
        return new FullTime(id,name,type,salary,bonus);
    }
    if(type=="PartTime") {
        float rate, hours;
        cout<<"Enter Rate: ";
        cin >> rate;
        cout<<"Enter Hours: ";
        cin >> hours;
        return new PartTime(id,name,type,rate,hours);
    }
    if(type=="Internship") {
        float stipend;
        cout<<"Enter Stipend: ";
        cin >> stipend;
        return new Intern(id,name,type,stipend);
    }
    else {
        cout<<"Invalid type\n";
        return nullptr;
    }
}
int main() {
    vector<Employee*> employees;
    string choice="yes";
    while(choice=="yes" || choice=="y") {
        Employee* employee = inputEmployee();
        if (employee) {
            employees.push_back(employee);
            cout << "Do you want to add another employee? (yes/no): ";
            cin >> choice;
            cin.ignore(100,'\n');
        }
    }
    cout<<"\nEmployees list: \n";
    for (Employee* employee: employees) {
        employee->display();
    }
    for (Employee* employee: employees) {
        delete employee;
    }
    return 0;
}
