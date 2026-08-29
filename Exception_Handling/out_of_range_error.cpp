#include <iostream>
#include <stdexcept>
#include<vector>
using namespace std;
int main() {
    vector<int> numbers={10,20,30};
    try {    //សាកប្រើធាតុទី១១នៃ numbers vector
        int value=numbers.at(10);
    }catch(const out_of_range& e) {
        cout<<"Out of range error caught: "<<e.what()<<endl;
    }
    return 0;
}