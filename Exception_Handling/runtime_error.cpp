#include<iostream>
#include <stdexcept>
using namespace std;
void openConfigFile(bool fileExists) {
    if (!fileExists) {   //បោះចេញនូវruntime error object មួយដោយភ្ជាប់ជាមួយឃ្លាកំហុសឆ្គង
        throw runtime_error("Configuration file is missing!");
    }
    cout<<"File opened successfully"<<endl;
}
int main () {
    try {
        openConfigFile(false);  //ឧបមាថាគ្មានឯកសារ
    }catch(const runtime_error& e) {
        cout<<"Runtime error caught: "<<e.what()<<endl;
    }
}