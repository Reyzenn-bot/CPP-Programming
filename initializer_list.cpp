#include <iostream>
using namespace std;
class Person {
    protected:
    int idNum_;
    string fullName_;
    public:
    Person(int idNum, string fullName): idNum_(idNum), fullName_(fullName) {}
};
class Student : public Person {
private:
    int id_;
    float gpa_;
    public:
    Student(int idNum, string fullName, int id, float gpa): Person(idNum, fullName), id_(id), gpa_(gpa) {}
    void display() {
        cout<<fullName_<<" has "<< idNum_
            <<" as nationality identification number,\n\t "<<id_
            <<" as student identification number,  and "<<gpa_<<" GPA."<<endl;
    }
};
int main() {
    Student student(12345678,"REYzenn",15,4.00);
    student.display();
    return 0;
}


