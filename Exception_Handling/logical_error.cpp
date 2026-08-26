#include<iostream>
#include<stdexcept> //use for logic error class
using namespace std;
void calculateDiscount(int age) {
    if (age<0) {
        throw logic_error("Age cannot be negative!");
    }
    cout<<"Discount applied.";
}
int main() {
    try {
        calculateDiscount(-5);
    }catch (const logic_error& le) {
        cout<<"Logic error caught: "<<le.what()<<"\n";
    }
    return 0;
}