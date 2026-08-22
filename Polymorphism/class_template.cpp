#include<iostream>
#include<string>
using namespace std;
template<typename T>   //បង្កើតទិន្នន័យទូទៅ
class Invoice {
private:
    T invoiceId;   //អាចផ្ទុកចំនួនគត់ក៏បាន ឃ្លាក៏បាន
    string customerName;
    string date;
    double amount;
    double taxRate;    //ជាភាគរយ ដូចជា តម្លៃ១០មានន័យ១០%
    public:
    Invoice(T id, string customer, string dt, double amt, double tax): invoiceId(id),customerName(customer),date(dt),amount(amt),taxRate(tax) {}
    double getTotal() const {
        return amount * (amount + taxRate/100.0);
    }
    void showInvoice() {
        cout<<"==============================";
        cout<<"Invoice Id: "<<invoiceId<<endl;
        cout<<"Customer: "<<customerName<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Amount: $"<<amount<<endl;
        cout<<"Tax Rate: "<<taxRate<<endl;
        cout<<"Total : $"<<getTotal()<<endl;
    }
};
int main() {
    //បញ្ជាក់ថាប្រភេទទិន្នន័យទូទៅTកំណត់យកជាint
    Invoice<int>inv1(100,"Oasis","2026-08-22",250.5,10);
    inv1.showInvoice();

    //បញ្ជាក់ថាប្រភេទទិន្នន័យទូទៅTកំណត់យកជាstring
    Invoice<string>inv2("INV-2026-08","Oscar","2026-08-22",499.99,5);
    inv2.showInvoice();
}