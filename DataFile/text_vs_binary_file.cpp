#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>  //batter for modern C++ than string.h
using namespace std;
int main() {
    fstream tf("contact book.txt", ios::out);  //create tf object ផ្ទុកទិន្នន័យក្នុង contact book.txt
    fstream bf("contact book.dat", ios::out);  //create bf object ផ្ទុកទិន្នន័យក្នុង contact book.dat

    char contactName[20], phoneNumber[15];   // create array of contactName and phoneNumber

    int i=0;
    char answer=0;

    if (tf.good() && bf.good()) {   // if open file successfully
        cout<<"\n\t Open files for writing successfully!\n";
        do {
            strcpy(contactName, "");
            strcpy(phoneNumber, "");
            cout<<"\nContact Name: ";
            cin.getline(contactName,20);
            cout<<"\nPhone Number: ";
            cin.getline(phoneNumber,15);
            tf<<contactName<<endl;  //ផ្ទុកតម្លៃនៃអថេរ contactName ក្នុង text file
            tf<<phoneNumber<<endl;  //ផ្ទុកតម្លៃនៃអថេរ phoneNumber ក្នុង text file
            //ផ្ទុកតម្លៃនៃអថេរ contactName and phoneNumber ក្នុង binary file
            bf.write(contactName,sizeof(contactName));
            bf.write(phoneNumber,sizeof(phoneNumber));
            if (tf.good() && bf.good()) {
                i++;
                cout<<"Add one more contact?(y/n) : ";
                cin>>answer;
                cin.ignore();
            }
        }while (answer=='y');
    }
    // close file
    tf.close();
    bf.close();

    cout<<"\t"<<i<<" contact(s) saved in contact book.txt and contact book.dat\n";
    tf.open("contact book.dat",ios::in);  // use tf object take data in text file
    bf.open("contact book.dat",ios::in | ios::binary);  // use bf object take data in binary file

    if (tf.good() && bf.good()) {
        cout<<"\n\tOpen contact book.txt file for reading successfully!\n";
        cout<<"\n"<<left<<setw(16)<<"Contact Name"<<setw(13)<<" Telephone Number";

        while (bf.read(contactName,sizeof(contactName)) && bf.read(phoneNumber,sizeof(phoneNumber))) {
            cout<<"\n"<<setw(16)<<contactName<<setw(13)<<phoneNumber<<endl;
        }
        bf.close();
        return 0;
    }
}