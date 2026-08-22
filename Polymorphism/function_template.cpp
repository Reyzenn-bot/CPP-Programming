#include<iostream>
#include<string>
using namespace std;
template<typename Type>    //function template សម្រាប់កំណត់តម្លៃធំបំផុត
Type getMax(Type value1 , Type value2) {
    return(value1>value2)?value1:value2;
}
int main() {
    int i1=100,i2=200;
    cout<<"Max of: "<<i1<<" and "<<i2<<" is "<<getMax(i1,i2)<<endl;

    float f1=55.45,f2=33.30;
    cout<<"Max of: "<<f1<<" and "<<f2<<" is "<<getMax(f1,f2)<<endl;

    char c1='A',c2='Z';
    cout<<"Max of: "<<c1<<" and "<<c2<<" is "<<getMax(c1,c2)<<endl;

    string s1="Apple",s2="Banana";
    cout<<"Max of: "<<s1<<" and "<<s2<<" is "<<getMax(s1,s2)<<endl;

    int n1=33; float n2=55.45;
    // cout<<"Max of: "<<n1<<" and "<<n2<<" is "<<getMax(n1,n2)<<endl;
}