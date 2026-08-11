#include <cstring>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Person {
private:
    int id;
    char name[16];
    char sex;
    float weight;
    float height;
    int age;
public:
    void input() {
        cout<<"Person\n";
        cout<<"ID: ";
        cin>>id;
        cin.ignore(1000,'\n');
        cout<<"Name: ";
        cin.get(name,16);
        cout<<"Sex: ";
        cin>>sex;
        cout<<"Weight(kg): ";
        cin>>weight;
        cout<<"Height(cm): ";
        cin>>height;
        cout<<"Age: ";
        cin>>age;
    }
    void output() {
        cout<<"\nID: "<<id<<"\nName: "<<name<<"\nSex: "<<sex
        <<"\nWeight: "<<weight<<"\nHeight: "<<height<<"\nAge: "<<age<<endl;
    }
};
int main() {
    int *ptrN=new int(2026);
    double *ptrD=new double(123.45);
    char *ptrC=new char('M');
    string *ptrS=new string("Year 1");
    char *ptrA=new char[15];
    Person *ptrP=new Person();
    strcpy(ptrA, "C++");

    cout<<"pointer to number: "<<*ptrN<<endl;
    cout<<"pointer to double floating number: "<<*ptrD<<endl;
    cout<<"pointer to character: "<<*ptrC<<endl;
    cout<<"pointer to string: "<<*ptrS<<endl;
    cout<<"pointer to array of characters: "<<*ptrA<<endl;

    cout<<"\n*** new , delete , (object) ***";
    ptrP->input();
    ptrP->output();
    //អោយអង្គចងចាំទៅប្រព័ន្ធប្រតិបត្តិការវិញ
    delete ptrN; delete ptrD; delete ptrC; delete ptrS; delete ptrA; delete ptrP;
    return 0;
}