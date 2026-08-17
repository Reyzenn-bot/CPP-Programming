#include<iostream>
using namespace std;
class S;  //ប្រកាស class S មុននឹងធ្វើជាfriendជាមួយ class C
class C {
private:
    string prop_;
    public:
    C(string prop) {
        prop_=prop;
    }
    friend class S;
};
class S {
    private:
    string attr_;
    public:
    S(string attr) {
        attr_=attr;
    }
    void method1inS() {
        C c("property of class C.\n");
        cout<<"\n\tMethod 1 in class S use"<<c.prop_<<"\n";
    }
    void method2inS() {
        C c("property of class C.\n");
        cout<<"\n\tMethod 2 in class S use"<<c.prop_<<"\n";
    }
};
int main() {
    S s("attribute of class S.\n");
    s.method1inS();
    s.method2inS();
}