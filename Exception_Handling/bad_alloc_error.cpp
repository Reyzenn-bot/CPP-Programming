#include<iostream>
#include<new>  //សម្រាប់សុំចែកអង្គចងចាំយកមកប្រើប្រាស់
using namespace std;
int main() {
    try {     //សាកសុំអង្គចងចាំសម្រាប់ផ្ទុកលេខចំនួនគត់ច្រើនបំផុត
        int* massiveArray=new int[100000000000000000];
        cout<<"Memory allocated!\n";
        delete[] massiveArray;
    }catch(bad_alloc& e) {
        cout<<"Memory error caught: "<<e.what()<<endl;
        cout<<"Your computer doesn't have enough RAM for that.\n";
    }
    return 0;
}