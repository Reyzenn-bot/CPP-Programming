#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Employee {
    protected:
    int id_;
    string name_;
    string type_;
    public:
    Employee(int id, string name, string type) : id_(id),name_(name),type_(type){}
    virtual ~Employee(){} //virtual destructor
    virtual double calculateSalary()=0;
    virtual void display() {
        cout<<id_<<", "<<name_<<", "<<type_;
    }
};
class FullTime : public Employee {
    protected:
    double baseSalary_, bonus_;
    public:
    FullTime(int id, string name, string type, double baseSalary, double bonus): Employee(id,name,type), baseSalary_(baseSalary),bonus_(bonus){}
    double calculateSalary() override{return baseSalary_ * bonus_;}
    void display() override {
        Employee::display();
        cout<<", "<<baseSalary_<<", "<<bonus_<<", $"<<calculateSalary()<<endl;
    }
};
class PartTime: public Employee {
    protected:
    float hourRate_;
    float workHours_;
    public:
    PartTime(int id, string name, string type, float hourRate, float workHours):Employee(id, name, type), hourRate_(hourRate), workHours_(workHours){}
    double calculateSalary() override{return hourRate_ + workHours_;}
    void display() override {
        Employee::display();
        cout<<", "<<hourRate_<<", "<<workHours_<<", $"<<calculateSalary()<<endl;
    }
};
class Intern: public Employee {
    protected:
    float stipend_;
    public:
    Intern(int id, string name, string type, float stipend): Employee(id, name, type), stipend_(stipend){}
    double calculateSalary() override{return stipend_;}
    void display() override {
        Employee::display();
        cout<<", "<<stipend_<<", $"<<calculateSalary();
    }
};
#endif