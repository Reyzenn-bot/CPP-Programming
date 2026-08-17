#include <iostream>
using namespace std;
class Account {
    private:
    int id_;
    string name_;
    double balance_;
    public:
    Account(int id,string name,double balance=0.0): id_(id), name_(name), balance_(balance) {}
    void display() const{
        cout<<"\tID: "<<id_
            <<" | Name: "<<name_
            <<" | Balance: "<<balance_<<endl;
    }
    void deposit(int accId,double amount) {
        if (accId == id_) {
            balance_ += amount;
            cout<<"Deposited $"<<amount<<" | New Balance: $"<<balance_<<endl;
        }
        else {
            cout<<"Invalid account ID!\n";
        }
    }
    void deposit(string accName,double amount) {
        if (accName == name_) {
            balance_ += amount;
            cout<<"Deposited $"<<amount<<" | New Balance: $"<<balance_<<endl;
        }
        else {
            cout<<"Invalid account Name!\n";
        }
    }
};
int main() {
    cout<<"Create new account\n"<<endl;
    Account acc1(12,"Reyzenn",255);
    acc1.display();
    cout<<endl;

    cout<<"Deposit using account num and amount!\n";
    acc1.deposit(12,100);
    acc1.display();
    cout<<endl;

    cout<<"Deposit using account name and amount!\n";
    acc1.deposit("Reyzenn",150);
    acc1.display();
    return 0;
}