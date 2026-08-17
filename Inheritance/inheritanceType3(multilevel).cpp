#include<iostream>
using namespace std;
class Person {
protected:
    int id;
    string name;
    public:
    void input();
    void output();
};
class Student: public  Person {
    protected:
    float gpa;
    public:
    void input();
    void output();
};
class PostGraduate: public  Student {
    protected:
    string specialization;
    public:
    void input();
    void output();
};
int main() {
    cout<<"Post Graduate\n";
    PostGraduate pg1;
    pg1.input();
    pg1.output();
    cout<<endl;
    return 0;
}
void Person::input() {
    cout<<"ID: ";
    cin>>id;
    cin.ignore(100,'\n');
    cout<<"Name: ";
    getline(cin,name);
}
void Person::output() {
    cout<<"\t\t"<<id<<". "<<name;
}

void Student::input() {
    Person::input();
    cout<<"GPA: ";
    cin>>gpa;
    cin.ignore(100,'\n');
}
void Student::output() {
    Person::output();
    cout<<" has a "<<gpa<<" PGA";
}

void PostGraduate::input() {
    Student::input();
    cout<<"Specialization: ";
    getline(cin,specialization);
}
void PostGraduate::output() {
    Student::output();
    cout<<", Specialization in "<<specialization<<endl;
}