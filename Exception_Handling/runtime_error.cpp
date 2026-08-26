#include<iostream>
#include <stdexcept>
using namespace std;
void openConfigFile(bool fileExists) {
    if (!fileExists) {
        throw runtime_error("Configuration file is missing!");
    }
    cout<<"File opened successfully"<<endl;
}
int main () {
    try {
        openConfigFile(false);
    }catch(const runtime_error& e) {
        cout<<"Runtime error caught: "<<e.what()<<endl;
    }
}