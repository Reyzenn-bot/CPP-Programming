#include <iostream>
#include <vector>
using namespace std;
class Employee {
  protected:
  int id_;
  string name_;
  string type_;
  public:
  Employee(int id, string name, string type) : id_(id), name_(name), type_(type) {}
  virtual ~Employee() {} //destructor
  double calculateSalary() {return 0.0;}
  virtual void display() {
    cout<<id_<<", "<<name_<<", "<<type_; //late binding
  }
};
class FullTime: public Employee {
  private:
  double BaseSalary_;
  double bonus_;
  public:
  FullTime (int id, string name, string type, double BaseSalary, double bonus) : Employee(id, name, type), BaseSalary_(BaseSalary), bonus_(bonus) {}
  double calculateSalary() {return BaseSalary_ + bonus_;}
  void display()  override {
    Employee::display();
    cout<<", "<<BaseSalary_<<", "<<bonus_<<", $"<<calculateSalary()<<endl;
  }
};
class PartTime: public Employee {
  protected:
  float hourRate_, workHours_;
  public:
  PartTime(int id, string name, string type, float hourRate, float workHours) : Employee(id, name, type), hourRate_(hourRate), workHours_(workHours) {}
  double calculateSalary() {return hourRate_ * workHours_;}
  void display()  override {
    Employee::display();
    cout<<", "<<hourRate_<<", "<<workHours_<<", $"<<calculateSalary()<<endl;
  }
};
class Intern: public Employee {
  protected:float stipend_;
  public:
  Intern(int id, string name, string type, float stipend): Employee(id, name, type), stipend_(stipend) {}
  double calculateSalary() {return stipend_;}
  void display()  override {
    Employee::display();
    cout<<", "<<stipend_<<", $"<<calculateSalary()<<endl;
  }
};
int main() {
  vector<Employee*> employees;
  employees.push_back(new FullTime(101, "An Pin", "Full-Time",500,100));
  employees.push_back(new PartTime(102, "In Dara", "Part-Time",20,20));
  employees.push_back(new Intern(103, "Ra Dai","Internship",80));
  employees.push_back(new FullTime(104, "Y Sony","Full-Time",600,120));
  employees.push_back(new PartTime(105, "Y Heng","Part-Time",25,10));

  for (Employee* employee: employees) {
    employee->display();
    cout<<endl;
  }
  for (Employee* employee: employees) {
    delete employee;
  }
  return 0;
}