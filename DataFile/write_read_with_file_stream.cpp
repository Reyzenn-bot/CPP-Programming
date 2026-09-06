#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>  //ប្រើ string ដូចfile ដូចជាទាញយកតម្លៃដែលជាផ្នែកមួយនៃឃ្លា។
#include <string>
using namespace std;
class Employee {
    private:
    int id;
    string name;
    double salary;
    public:
    Employee() : id(0), name(""), salary(0.0) {}  //constructor
    void input() {
        cout<<"Employee ID : ";
        cin>>id;
        cin.ignore(100,'\n');
        cout<<"Employee Name : ";
        getline(cin,name);
        cout<<"Employee Salary : ";
        cin>>salary;
    }
    //មុខងារសម្រាប់ save ID, name and salary in file
    void saveToFile(string& filename) {
        fstream file(filename, ios::app);  //បើកឯកសារដើម្បីផ្ទុកទិន្នន័យតពីទិន្នន័យមានស្រាប់ក្នុងឯកសារ
        file<<id<<",  "<<name<<",  "<<salary<<endl;  //ផ្ទុកទិន្នន័យពីបុគ្គលិកក្នុងឯកសារតាមទម្រង់ ID, name and salary
        file.close();
    }
    //មុខងាររាយពត៌មានបុគ្គលិកទាំងក្នុងទម្រង់ជាតារាង។ប្រើ class ហៅអោយបានដោយសារជា static method
    static void displayAll(string& filename) {
        ifstream inFile(filename);   //បើកឯកសារដើម្បីទាញយកទិន្នន័យ
        cout<<"\n----------------------------------------\n";
        cout<<left<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(10)<<"Salary"<<endl;
        cout<<"----------------------------------------\n";

        int id;
        string name, line, value;
        double salary;

        while (getline(inFile,line)) {
            stringstream values(line);   //បង្កើត string stream ឈ្មោះ values ផ្ទុកឃ្លាមានក្នុងអថេរ line
            getline(values, value,',');   //ចេញពីឃ្លា values ទាញយកទិន្នន័យរហូតដល់សញ្ញា , ទើបឈប់ហើយយកមកដាក់ក្នុងname
            id=stoi(value);   //String TO Integer ដូរឃ្លាជាចំនួនគត់
            getline(values,name,',');   //ចេញពីឃ្លា values បន្តទាញយកទិន្នន័យរហូតដល់សញ្ញា , ទើបឈប់ហើយយកមកដាក់ក្នុងvalue
            getline(values,value,',');
            salary=stod(value);   //String TO Double ដូរពីឃ្លាទៅចំនួនទសភាគ
            cout<<left<<setw(10)<<id<<setw(20)<<name<<setw(10)<<salary<<endl;
        }
        cout<<"----------------------------------------\n";
        inFile.close();
    }

};
int main() {
    string filename="employee.txt";
    char choice='y';
    while(choice=='Y' || choice=='y') {
        Employee emp;  //create object
        emp.input();
        emp.saveToFile(filename);

        Employee::displayAll(filename);
        cout<<"Do you want to add another employee? (y/n): ";
        cin.ignore(100,'\n');
        cin>>choice;
    }
    return 0;
}