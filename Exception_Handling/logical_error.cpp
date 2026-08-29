#include<iostream>
#include<stdexcept> //use for logic error class
using namespace std;
void calculateDiscount(int age) {
    if (age<0) {   //បោះចេញនូវ logical error objectមួយដោយភ្ជាប់ជាមួយនូវឃ្លាកំហុស Age cannot be negative!
        throw logic_error("Age cannot be negative!");
    }
    cout<<"Discount applied.";
}
int main() {
    try {
        calculateDiscount(-5);
    }catch (const logic_error& le) {   //what ផ្តល់នូវអ្វីដែលឃ្លាបានភ្ជាប់មកជាមួយ
        cout<<"Logic error caught: "<<le.what()<<"\n";
    }
    return 0;
}