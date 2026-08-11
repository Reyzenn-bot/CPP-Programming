#include <iostream>
using namespace std;
class Person {
    protected:
    string name_;
    int yearBorn_;
    public:
    void input();
    void output();
};
class Student : public Person {
private:
    int studenetID_;
public:
    void input();
    void output();
};
int main() {
    Person person1;
    cout<<"Person"<<endl;
    person1.input();
    person1.output();

    cout<<endl<<"Student"<<endl;
    Student student1;
    student1.input();
    student1.output();
    cout<<endl;
    return 0;
}
void Person::input() {
    cout<<"\tName: ";
    getline(cin,name_);
    cout<<"\tYear Born: ";
    cin>>yearBorn_;
}
void Person::output() {
    cout<<endl<<name_<<" was born in "<<yearBorn_<<"."<<endl;
}
void Student::input() {
    cout<<"\tID: ";
    cin>>studenetID_;
    cin.ignore(1000,'\n');
    Person::input();
}
void Student::output() {
    Person::output();
    cout<<"His Identification number is "<<studenetID_<<"."<<endl;
}