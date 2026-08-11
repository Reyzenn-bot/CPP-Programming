#include<iostream>
using namespace std;
class Person {
    protected:
    string name;
    int id;
    public:
    void input();
    void output();
};
class Student :public Person {
    private:
    float gpa;
    public:
    void input();
    void output();
};
int main() {
    Person person1;
    cout<<"Person"<<endl;
    person1.input();
    person1.output();

    Student student1;
    cout<<"\n\nStudent"<<endl;
    student1.input();
    student1.output();
    cout<<"\n\n";
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
    cout<<"\t\t"<<id<<"."<<name<<endl;
}
void Student::input() {
    Person::input();
    cout<<"\tGPA: ";
    cin>>gpa;
}
void Student::output() {
    Person::output();
    cout<<"has a "<<gpa<<" PGA";
}