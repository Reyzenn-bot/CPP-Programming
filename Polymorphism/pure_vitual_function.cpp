#include <iostream>
#include<vector>
using namespace std;
class Employee {
  protected:
  int id_;
  string name_;
  string type_;
  public:
  Employee(int id, string name, string type) : id_(id),name_(name),type_(type){}
  virtual ~Employee(){} // must have for clean up memory use by objects
  virtual double calculateSalary()=0;
  virtual void displaySalary() {
    cout<<id_<<", "<<name_<<", "<<type_; //virtual function
  }
};
class FullTime: public Employee {
  protected:
  double salary_;
  double bonus_;
  public:
  FullTime(int id, string name, string type, double salary, double bonus) : Employee(id,name,type), salary_(salary), bonus_(bonus){}
  double calculateSalary() override{return salary_+bonus_;}
  void displaySalary() override {
    Employee::displaySalary();
    cout<<", "<<salary_<<", "<<bonus_<<", $"<<calculateSalary()<<endl;
  }
};
class PartTime: public Employee {
  protected:
  float hourRate_;
  float workHours_;
  public:
  PartTime(int id, string name, string type, float hourRate, float workHours): Employee(id,name,type), hourRate_(hourRate), workHours_(workHours){}
  double calculateSalary() override{return hourRate_*workHours_;}
  void displaySalary() override {
    Employee::displaySalary();
    cout<<", "<<hourRate_<<", "<<workHours_<<", $"<<calculateSalary()<<endl;
  }
};
class Intern: public Employee {
  protected:
  float stipend_;
  public:
  Intern (int id, string name, string type, float stipend): Employee(id,name,type), stipend_(stipend){}
  double calculateSalary() override{return stipend_;}
  void displaySalary() override {
    Employee::displaySalary();
    cout<<", "<<stipend_<<", $"<<calculateSalary()<<endl;
  }
};
int main() {
  vector<Employee*> employees;
  employees.push_back(new FullTime(101, "An Pin", "Full-Time",500, 100));
  employees.push_back(new PartTime(102, "In Dara", "Part-Time",20, 20));
  employees.push_back(new Intern(103, "Ra Dai", "Internship",80));
  employees.push_back(new FullTime(104, "Y Sony", "Full-Time",600,120));
  employees.push_back(new PartTime(105, "Y Heng", "Part-Time",25,100));
  for (Employee* employee: employees) {
    employee->displaySalary();  //3 using base class pointer
  }
  cout<<endl;
  for (Employee* employee: employees) {
    delete employee;  // clean up memory used by object
  }
  return 0;
}