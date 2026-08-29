#include <iostream>
#include<fstream>
using namespace std;
int main() {
    /*បើ text file 1.txt មិនទាន់មាន។បង្កើត file ថ្មីនេះនិងបើកវា។
    បើ text file.txt មានហើយក្នុង folder បច្ចុប្បន្នបើកវា។
    ហើយ file នេះត្រូវបានតាងដោយ object មានឈ្មោះថា outFile។*/
    ofstream outFile("text file 1.txt");
    if (!outFile) {  //បើបង្កើតឬបើក file មិនបាន
        cout<<"Error opening file!"<<endl;
        return 1;
    }
    //ប្រើសញ្ញាប្រមាណវិធី<<ដើម្បីផ្ទុកទិន្នន័យបានរៀបចំក្នុង text file.txt ដែលតាងដោយ outFile object
    outFile<<"Hello C++ File Using!\n";
    outFile<<"Year: "<<1<<endl;
    outFile<<"Semester: "<<2<<endl;
    outFile.close();   //បិទឯកសារ។
    cout<<"\n\tData written successfully using << operator!\n\n";
    return 0;
}