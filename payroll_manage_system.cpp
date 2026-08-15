#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
class Employee {
    protected:
    int id;
    string name;
    string type;
    public:
    Employee(int ID, string Name, string Type): id(ID), name(Name), type(Type) {}
    virtual ~Employee() {}
    virtual double getBaseSalary() const {return 0;}
    virtual double getBonus() const {return 0;}
    virtual double getHourlyRate() const {return 0;}
    virtual double getHoursWorked() const {return 0;}
    virtual double getStipend() const {return 0;}
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        cout<<left<<setw(8)<<id
            <<setw(12)<<name
            <<setw(12)<<type;
        if (getBaseSalary() > 0.0) {
            cout<<setw(14)<<getBaseSalary();
        }else {
            cout<<setw(14)<<"-";
        }
        if (getBonus() > 0.0) {
            cout<<setw(10)<<getBonus();
        }else {
            cout<<setw(10)<<"-";
        }
        if (getHourlyRate()>0.0) {
            cout<<setw(14)<<getHourlyRate();
        }else {
            cout<<setw(14)<<"-";
        }
        if (getHoursWorked() > 0.0) {
            cout<<setw(14)<<getHoursWorked();
        }else {
            cout<<setw(14)<<"-";
        }
        if (getStipend() > 0.0) {
            cout<<setw(10)<<getStipend();
        }else {
            cout<<setw(10)<<"-";
        }
    }
    int getID() const {return id;}
    string getName() const {return name;}
};

class FullTime: public Employee {
private:
    double baseSalary;
    double bonus;
    public:
    FullTime(int ID, string Name, string Type,double salary, double Bonus):
        Employee(ID, Name, Type), baseSalary(salary), bonus(Bonus) {}
    double getBaseSalary() const override {return baseSalary;}
    double getBonus() const override {return bonus;}
    double calculateSalary() const override{
        return baseSalary + bonus;
    }
    void displayInfo() const override {
        Employee::displayInfo();
        cout<<setw(18)<<calculateSalary()<<endl;
    }
};
class PartTime: public Employee {
    private:
    double hourlyRate;
    int hours;
    public:
    PartTime(int ID, string Name,string Type, double HourlyRate, int Hours):
        Employee(ID, Name, Type), hourlyRate(HourlyRate), hours(Hours) {}
    double getHourlyRate() const override {return hourlyRate;}
    double getHoursWorked() const override {return hours;}
    double calculateSalary() const override {
        return hourlyRate * hours;
    }
    void displayInfo() const override {
        Employee::displayInfo();
        cout<<setw(18)<<calculateSalary()<<endl;
    }
};
class Internship: public Employee {
    private:
    double stipend;
    public:
    Internship(int ID, string Name,string Type, double Stipend):
        Employee(ID, Name, Type), stipend(Stipend) {}
    double getStipend() const override {return stipend;}
    double calculateSalary() const override {
        return stipend;
    }
    void displayInfo() const override {
        Employee::displayInfo();
        cout<<setw(18)<<calculateSalary()<<endl;
    }
};
int main() {
    vector<Employee*> employees;

    employees.push_back(new FullTime(101, "An Pin","Full-Time" ,500, 100));
    employees.push_back(new PartTime(102, "In Dara","Part-Time", 2, 120));
    employees.push_back(new Internship(103, "Ra Dari","Internship", 80));
    employees.push_back(new FullTime(104, "Y Sony","Full-Time" ,600,120));
    employees.push_back(new PartTime(105, "Y Heng", "PartTime",2.5, 100));

    cout<<"=============================================================================================================\n";
    cout<<"                                       Payroll Management System                                             \n";
    cout<<"=============================================================================================================\n";
    cout<<left<<setw(8)<<"ID"
    <<setw(12)<<"Name"
    <<setw(12)<<"Type"
    <<setw(14)<<"Base Salary"
    <<setw(10)<<"Bonus"
    <<setw(14)<<"Hourly Rate"
    <<setw(14)<<"Hours Worked"
    <<setw(10)<<"Stipend"
    <<setw(14)<<"Total Salary($)"<<endl;
    cout<<"=============================================================================================================\n";

    double totalPayroll=0.0;
    for (const auto& emp: employees) {
        emp->displayInfo();
        totalPayroll+=emp->calculateSalary();
    }

    cout<<"=============================================================================================================\n";
    cout<<"Total Payroll : $"<<totalPayroll<<" USD"<<endl;
    cout<<"=============================================================================================================\n\n";

    for (auto& emp: employees) {
        delete emp;
    }
    return 0;
}