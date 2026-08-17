#include<iostream>
#include<string>
using namespace std;
class BankAccount {
private:
    string ownerName;
    double balance;
public:
    BankAccount() {
        ownerName = "";
        balance = 0.0;
    }
    BankAccount(string ownerName, double balance) {
        this->ownerName = ownerName;
        this->balance=balance;
    }
    ~BankAccount() {
        cout<<"Account closed for "<<ownerName<<". Freeing resources.\n";
    }
};
int main() {
    BankAccount uAccount;  //default constructor ដើរ
    BankAccount iAcccount("Reyzenn",10000);  //parameterized constructor ដើរ
}