#include<iostream>
#include<string>
using namespace std;
class Person {
private:
    int id=0;
    string name="";
public:
    Person() {   // default constructor
        id=0;
        name="";
    }
    Person(int id, string name) {   // parameterized constructor
        this->id=id;   //this = this object (pointer)
        this->name=name;
    }
    int getId() const {   //getter
        return id;
    }
    string getName() const {
        return name;
    }
    void getPersonInfo() const{   //get ម្តងបានច្រើន
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
    }
};

int main() {
    Person person1;
    cout<<person1.getId()<<endl;
    cout<<person1.getName()<<endl;
    person1.getPersonInfo();
    Person person2(101,"Jo");
    Person person3(102,"Jo mes");
    person2.getPersonInfo();
    person3.getPersonInfo();
    return 0;
}