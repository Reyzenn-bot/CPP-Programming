#include<iostream>
#include<fstream>
using namespace std;
int main() {
    //បើមានឯកសារសម្អាតទិន្នន័យក្នុងឯកសារ បើមិនមានបើកឯកសារថ្មី
    fstream file("tellX seekg get.bin", ios::in | ios::binary | ios::out| ios::trunc);

    //ប្រាប់ទីតាំង
    cout<<"\nbefore writing - put position: "<<file.tellp()<<endl;

    file<<"ABCDEFGHI";  //ផ្ទុកទិន្នន័យក្នុងឯកសារ
    cout<<"\"ABCDFGHI\" is wrote."<<endl;
    //ប្រាប់ទីតាំងបច្ចុប្បន្ន
    cout<<"after writing - put position: "<<file.tellp()<<endl;
    //រំកិលទៅខាងដើមឯកសារ
    file.seekp(0, ios::beg);
    cout<<"after writing - move to the begining of file - get position: "<<file.tellg()<<endl;

    int p=1;
    char c=0;
    while (p>0 && p<10) {
        cout<<"---------\n123456789\nABCDEFGHI\n---------\n";
        cout<<"character position, you want to get(1-9): ";   //ប្រាប៉អោយគេបញ្ចូលទីតាំងនៃតួអក្សរ
        cin>>p;

        file.seekp(p-1, ios::beg);
        file.get(c);
        cout<<"got character: "<<c<<"\n\n";
        c=0;
    }
    file.close();

    return 0;
}