#include<iostream>
#include<fstream>
#include<filesystem>
using namespace std;
int main() {
    fstream file("seekX put.bin", ios::in | ios::binary | ios::out | ios::trunc);
    file<<"ABCDEFGHI";    //ផ្ទុកទិន្នន័យក្នុងឯកសារ

    int pos;
    char newChar;
    while (true) {
        file.seekg(0, ios::beg);   //រំកិលទីតាំងទៅខាងដើមឯកសារ
        char line[10]={0};     //arrayផ្ទុកឃ្លាច្រើនបំផុត៩តួអក្សរ
        file.read(line,9);    //ទាញ៩អក្សរពីឯកសារ
        line[9]='\0';     //ធាតុទី១០នៃarrayដាក់សញ្ញាបញ្ចប់ឃ្លា

        cout<<"\n---------\n";
        cout<<"123456789\n"<<line<<endl;
        cout<<"---------\n";

        //ប្រាប់គេអោយបញ្ចូលទីតាំងអក្សរត្រូវជំនួស ដកឃ្លា អក្សរថ្មីត្រូវបានជំនួសអក្សរចាស់
        //1 U មានន័យថាអក្សរទី១នឹងជំនួសដោយអក្សរU
        cout<<"Character position(1-9) and new character (0 to quit): ";
        cin>>pos;
        if (pos<=0 || pos>9) {
            break;
        }
        cin>>newChar;
        file.seekp(pos-1,ios::beg);   //រំកិលទៅទីតាំងបានបញ្ចូលខាងលើ
        file.put(newChar);   //ផ្ទុកអក្សរថ្មី
        file.flush();   //រក្សាទុកទិន្នន័យថ្មីទើបកែក្នុងឯកសាររួច
    }
    file.close();
    cout<<"\n";
    return 0;
}