#include<iostream>
#include<string>
using namespace std;
class BankAccount {
private:
    string ownerName;
    double balance;
public:
   BankAccount(string name, double InitialBalance) {
       ownerName = name;
       balance = InitialBalance;
   }
    void deposit(double amount) {
       if (amount>0) {
           balance+=amount;
           cout<<"Successfully deposit $"<<amount<<" for"<<ownerName<<".\n";
       }else {
           cout<<"Invalid deposit amount.\n";
       }
   }
    void displayBalance() {
       cout<<ownerName<<"'s current balance is : $"<<balance<<'\n';
   }
};
int main() {
    BankAccount myAccount("Alice",10000);
    BankAccount yourAccount("Bob",500);
    myAccount.deposit(5000);
    myAccount.displayBalance();
    yourAccount.displayBalance();
    return 0;
}