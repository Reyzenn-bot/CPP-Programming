#include<iostream>
using namespace std;
class Student {
    class Date {
    private:
        int day , month, year;
        public:
        void input() {
            cin>>day>>month>>year;
        }
        void display() {
            cout<<day<<"/"<<month<<"/"<<year<<endl;
        }
    };
private:
    int id;
    string name;
    Date birthDate;
public:
    void input() {
        cout<<"student ID: ";
        cin>>id;cin.ignore(1000,'\n');
        cout<<"Student Name: ";
        getline(cin,name);
        cout<<"Birth Date(day month year): ";
        birthDate.input();
    }
    void display() {
        cout<<"Student ID: "<<id<<endl;
        cout<<"Student Name: "<<name<<endl;
        cout<<"birth Date: ";
        birthDate.display();
        cout<<endl;
    }
};
int main() {
    Student student;
    student.input();
    cout<<endl;
    student.display();
    return 0;
}