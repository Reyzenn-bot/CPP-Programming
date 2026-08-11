#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Student {
    public:
    class Date {
    private:
        int day , month, year;
    public:
        Date() {
            day=1;
            month=1;
            year=2000;
        }
        Date(int d, int m, int y) {
            day=d;
            month=m;
            year=y;
        }
        void input() {
            cin>>day>>month>>year;
        }
        void display() {
            cout<<toString();
        }
        //បង្កើតមុខងារtoStringដែលអោយត្រលប់នូវឃ្លាday/month/year
        string toString() const {  //to_string ជា built-in function សម្រាប់ដូរលេខទៅជាឃ្លា
            string dateString=to_string(day)+"/"+to_string(month)+"/"+to_string(year);
            return dateString;
        }

    };
private:
    int id;
    string name;
    Date birthDate;
public:
    Student() {
        id=0;
        name="";
        birthDate=Date(1,1,2000);
    }
    Student(int i,string n,Date d) {
        id=i;
        name=n;
        birthDate=d;
    }
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
        cout<<"\n====================\n";
    }
    void printDetail() {
        cout<<right<<endl;
        cout<<setw(12)<<"ID: "<<id<<endl;
        cout<<setw(12)<<"Name: "<<name<<endl;
        cout<<setw(12)<<"Birth date: ";
        this->birthDate.display();
        cout<<"\n";
    }
    void printRow() {
        cout<<left<<setw(7)<<id<<setw(17)<<name<<setw(12);
        cout<<birthDate.toString();
        cout<<endl;
    }
};
void printDetails(Student student[], int n) {
    for (int i=0; i<n; i++) {
        student[i].printDetail();
        cout<<endl;
    }
}
void printRows(Student student[], int n) {
    cout<<endl;
    cout<<left<<setw(7)<<"ID"<<setw(17)<<"Name"<<setw(12)<<"BirthDate"<<endl;
    for (int i=0; i<n; i++) {
        student[i].printRow();
        cout<<endl;
    }
}
int main() {
    Student student[3]={  //បង្កើតarray of studentនិងផ្តល់តម្លៃដំបូងរបស់និស្សិតបីនាក់
        Student(001,"bane",Student::Date(1,2,2000)),
        Student(002,"Akai",Student::Date(2,1,2001)),
        Student(003,"Gusion",Student::Date(9,4,2003)),
    };
    printDetails(student,3);
    printRows(student,3);
    // student[0].display();
    // student[1].display();
    // student[2].display();
    return 0;
}