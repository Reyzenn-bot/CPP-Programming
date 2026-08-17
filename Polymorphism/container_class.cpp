#include<iostream>
using namespace std;
class Date {
private:
    int day_;
    int month_;
    int year_;
    public:
    Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}
    void output() {
        cout << day_ << "/" << month_ << "/" << year_ << endl;
    }
};
class Person {
private:
    int idNum_;
    string fullName_;
    Date birthDate_;  //birthDate property is object in Date class
    public:
    Person(int idNum, string fullName, int day, int month, int year): idNum_(idNum), fullName_(fullName), birthDate_(day,month,year) {}
    void display() {
        cout<<"\n\t"<<idNum_<<' '<<fullName_<<" Born on ";
        birthDate_.output();

    }
};
int main() {
    Person person(12345678,"Reyzenn",15,12,2007);
    person.display();
    return 0;
}