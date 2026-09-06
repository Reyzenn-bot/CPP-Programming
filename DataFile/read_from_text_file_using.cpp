#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ifstream inFile("text file 1.txt");  //បើក text file 1.txt ហើយ fileនេះត្រូវបានតាងដោយ inFile object
    if (!inFile) {
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    string word;
    while (inFile >> word) {    //ប្រើសញ្ញា>>ដើម្បីទាញទិន្នន័យម្តងមួយពាក្យពី inFile (text file 1.txt)មកផ្ទុកក្នុងអថេរ word
        cout<<word<<endl;    //បង្ហាញពាក្យទើបទាញចេញពិ text file 1.txt
    }
    inFile.close();

    cout<<"\n\t read word by word successfully using >> operator!\n\n";
    return 0;
}