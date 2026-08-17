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
class Staff:public Person {
    protected:
    string department;
    public:
    void input();
    void output();
};
class Lecturer:public Person {
    protected:
    string course;
    public:
    void input();
    void output();
};
int main() {
    cout<<"Staff\n";
    Staff staff1;
    staff1.input();
    staff1.output();

    cout<<"Lecturer\n";
    Lecturer lecturer1;
    lecturer1.input();
    lecturer1.output();
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
    cout<<id<<". "<<name;
}
void Staff::input() {
    Person::input();
    cout<<"Department: ";
    getline(cin,department);
}
void Staff::output() {
    cout<<" work in "<<department<<" department."<<endl;;
}
void Lecturer::input() {
    Person::input();
    cout<<"Course: ";
    getline(cin,course);
}
void Lecturer::output() {
    Person::output();
    cout<<", teaches "<<course<<" course.";
}