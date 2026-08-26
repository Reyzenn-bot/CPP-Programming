#include<iostream>
#include<new>
using namespace std;
int main() {
    try {
        int* massiveArray=new int[1000000000000000];
        cout<<"Memory allocated!\n";
        delete[] massiveArray;
    }catch(bad_alloc& e) {
        cout<<"Memory error caught: "<<e.what()<<endl;
        cout<<"Your computer doesn't have enough RAM for that.\n";
    }
    return 0;
}