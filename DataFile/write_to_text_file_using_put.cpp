#include<iostream>
#include<fstream>
using namespace std;
int main() {
    //បង្កើតឬបើកឯកសារ text file 2.txt
    ofstream outFile("text file 2.txt");

    //បើបង្កើតឬបើកឯកសារមិនបាន បង្ហាញកំហុសឆ្គងហើយបិទ app។
    if (!outFile) {
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    //បង្កើតអថេរផ្ទុកឃ្លា
    string text="put() writes a single character at a time to text file.\n";

    //ប្រើ put method ដើម្បីម្តងមួយអក្សរៗក្នុងឯកសារ។
    for (char ch: text) {
        outFile.put(ch);
    }
    outFile.close();  //បិទឯកសារ។
    cout<<"\n\tData written successfully using put() method.\n"<<endl;
    return 0;
}