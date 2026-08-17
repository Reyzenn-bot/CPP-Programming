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
class Staff :public Person {
protected:
    string department;
    public:
    void input();
    void output();
};
class Student :public Person {
    protected:
    float gpa;
    public:
    void input();
    void output();
};
class PostGraduate :public Student {
    protected:
    string specialization;
    public:
    void input();
    void output();
};
class ResearchAssist :public Staff, public PostGraduate {
    protected:
    string project;
    public:
    void input();
    void output();
};
int main() {
    cout<<"Staff\n";
    ResearchAssist assistance1;
    assistance1.input();
    cout<<endl;
    assistance1.output();
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
    Person::output();
    cout<<" work in "<<department<<" department";
}
void Student::input() {
    Person::input();
    cout<<"GPA: ";
    cin>>gpa;
    cin.ignore(100,'\n');
}
void Student::output() {
    Person::output();
    cout<<" has a "<<gpa<<" PGA.";
}
void PostGraduate::input() {
    Student::input();
    cout<<"Specialization: ";
    getline(cin,specialization);
}
void PostGraduate::output() {
    Student::output();
    cout<<", Specialization in"<<specialization;
}
void ResearchAssist::input() {
    Staff::input();
    cout<<"Project: ";
    getline(cin,project);
    cout<<"Research Assistance ";
    PostGraduate::input();
}
void ResearchAssist::output() {
    cout<<PostGraduate::name<<" is a research assistant of "<<Staff::name<<" on "<<project<<" project.";
}