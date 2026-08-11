#include<iostream>
#include<string>
using namespace std;
class bankAccount {
private:
    string ownerName;
    double balance;
public:
    bankAccount() {
        ownerName="";
        balance=0.0;
    }
    bankAccount(string name, double bal) {
        this->ownerName=name;
        this->balance=bal;
    }
    double getBalance() const {  //use getter ដើម្បីអោយពិភពខាងក្រៅមើល property បាន
        return balance;
    }
    string getOwnerName() const{  //const ធានាតម្លៃ property នឹងមិនត្រូវបានផ្លាស់ប្តូរទេ
        return ownerName;
    }
    void displayAccountInfo() const {
        cout<<"Account holder: "<<ownerName<<"\n";
        cout<<"Current balance: $"<<balance<<"\n";
    }
    bool isOverdraw() const{   //Predicates ជាប្រភេទgetterម៉្យាងដែលផ្តល់តម្លៃ true/false តបនឹងសំណួរអំពីស្ថានភាពនៃ property
        return balance<0.0;
    }
    void deposit(double amount) {
        if (amount>0) {
            balance+=amount;
        }
    }
    bool withdraw(double amount) {
        if (amount>0 && balance>=amount) {
            balance-=amount;
            return true;  //if success
        }
        return false;  //if failed
    }
    ~bankAccount() {
        cout<<"\nAccount closed for "<<ownerName<<". Freeing resources.\n";
    }
};
int main() {
    cout<<"\5\5\5 BANKING SYSTEM INITIALIZED \5\5\5\n\n";
    bankAccount iAccount("Reyzenn",10000);  //parameterized constructor ដើរ
    bankAccount savingsAccount;  //default constructorដើរ
    iAccount.displayAccountInfo();
    iAccount.deposit(5000);
    iAccount.displayAccountInfo();

    cout<<"\n\3\3\3 Testing Overdraw feature \3\3\3\n";
    iAccount.withdraw(15000.00);
    iAccount.displayAccountInfo();

    // iAccount.withdraw(5000.00);
    // iAccount.displayAccountInfo();
}