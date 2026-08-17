#include <iostream>
using namespace std;
class Person {
protected:
    int id;
    string name;
    public:
    void input();
    void output();
};
class Student : public Person {
    protected:
    float gpa;
    public:
    void input();
    void output();
};
class Lecturer : public Person {
    protected:
    string course;
    public:
    void input();
    void output();
};
class TeachingAssistant: public Student,public Lecturer {
    public:
    void input();
    void output();
};
int main() {
    cout<<"Teaching Assistant\n";
    TeachingAssistant assistant1;
    assistant1.input();
    assistant1.output();
    cout<<endl<<endl;
    return 0;
}
void Person::input() {
    cout<<"\tID: ";
    cin>>id;
    cin.ignore(100,'\n');
    cout<<"\tName: ";
    getline(cin,name);
}
void Person::output() {
    cout<<"\t\t"<<id<<name;
}
void Student::input() {
    Person::input();
    cout<<"\tGPA: ";
    cin>>gpa;
    cin.ignore(100,'\n');
}
void Student::output() {
    Person::output();
    cout<<" has a "<<gpa<<endl;
}
void Lecturer::input() {
    Person::input();
    cout<<"\tCourse: ";
    getline(cin,course);
}
void Lecturer::output() {
    Person::output();
    cout<<", teaches "<<course<<"course"<<endl;
}
void TeachingAssistant::input() {
    Student::input();
    cout<<"\nLecturer\n";
    Lecturer::input();
}
void TeachingAssistant::output() {
    cout<<Student::name<<" is an assistant of lecturer's "<<Lecturer::name<<endl;
}