#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ifstream inFile("text file 1.txt");   //បើក text file 1.txt ហើយ fileនេះត្រូវបានតាងដោយ inFile object
    if (!inFile) {
        cout<<"\n\t Error in opening file!\n\n";
        return 1;
    }

    string line;
    while (getline(inFile, line)) {   //ប្រើgetline function ដើម្បីទាញទិន្នន័យម្តងមួយពាក្យពី inFile (text file 1.txt)មកផ្ទុកក្នុងអថេរ line
        cout << line << endl;   //បង្ហាញទិន្នន័យមួយបន្ទាត់ទើបទាញចេញពិ text file 1.txt
    }
    inFile.close();
    cout<<"\n\t read line by line successfully using getline function!\n\n";
}