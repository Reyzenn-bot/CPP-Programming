#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ifstream inFile("text file 2.txt");    //បើក text file 2.txt ហើយ fileនេះត្រូវបានតាងដោយ inFile object
    if (!inFile) {
        cout << "Error opening text file!" << endl;
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {  //ប្រើget function ដើម្បីទាញទិន្នន័យម្តងមួយអក្សរពី inFile (text file 2.txt)មកផ្ទុកក្នុងអថេរ ch
        cout << ch;   //បង្ហាញអក្សរទើបទាញចេញពិ text file 2.txt
    }
    inFile.close();
    cout<<"\n\t read character by character successfully using get function! \n\n";
    return 0;
}