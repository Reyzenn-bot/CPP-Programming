#include<iostream>
using namespace std;
struct Person {   //បង្កើត Person ជា structure ដែលមាន data members
    int id;
    string name;
    char sex;
    float height;
    float weight;
};
int main() {
    Person person;  //ប្រើ Person structure បង្កើត person variable
    cout<<"Person ID: ";
    cin>>person.id;
    cout<<"Person Name: ";
    cin>>person.name;
    cout<<"Sex: ";
    cin>>person.sex;
    cout<<"Height: ";
    cin>>person.height;
    cout<<"Weight: ";
    cin>>person.weight;
    float bmi=person.height*(person.weight*person.weight);
    cout<<"person BMI: "<<bmi<<endl;
    return 0;
}