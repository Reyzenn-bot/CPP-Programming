#include<iostream>
#include<string>
using namespace std;
struct Person {
    int id;
    string name;
    char sex;
    float height;
    int weight;
};
void inputPerson(Person &p) {
    cout<<"Enter ID: ";
    cin>>p.id;
    cin.ignore(1000,'\n');  //cin.ignore(1000,'\n')សម្អាតការចុះបន្ទាត់
    cout<<"Enter Name: ";
    getline(cin,p.name);
    cout<<"Enter Sex: ";
    cin>>p.sex;
    cin.ignore(1000,'\n');
    cout<<"Enter Height: ";
    cin>>p.height;
    cin.ignore(1000,'\n');
    cout<<"Enter Weight: ";
    cin>>p.weight;
    cin.ignore(1000,'\n');
}
void outputPerson(Person &p) {      //សញា & មុខប៉ារ៉ាម៉ែត្រ p បញ្ជាក់ថា pass by reference
    cout<<"ID: "<<p.id<<endl;
    cout<<"Name: "<<p.name<<endl;
    cout<<"Sex: "<<p.sex<<endl;
    cout<<"Height: "<<p.height<<endl;
    cout<<"Weight: "<<p.weight<<endl;
    cout<<endl;
}
int searchPerson(Person arr[],int size, int targetId) {  //រកតាមID
    for (int i=0; i<size; i++) {
        if (arr[i].id==targetId) {     //if ID of array = targetID
            return i;  //ផ្តល់លេខសម្គាល់ធាតុដែលបានរកឃើញនៅក្នុងអារ៉េ
        }
    }
    return -1;    //បើរកមិនឃើញក្នុងអារ៉េទាំងមូល
}
int main() {
    const int ARRAY_SIZE = 3;   //const=ថេរ
    Person people[ARRAY_SIZE];    //បង្កើតអារ៉េ Person structure
    cout<<"---Enter data for: "<<ARRAY_SIZE<<"People---";
    for (int i=0; i<ARRAY_SIZE; i++) {
        cout<<"\nPerson"<<(i+1)<<":"<<endl;
        inputPerson(people[i]);
    }
    cout<<"\n---Displaying All People---"<<endl;
    for (int i=0; i<ARRAY_SIZE; i++) {
        outputPerson(people[i]);
    }
    cout<<"\n---Searching for a Person---"<<endl;
    int searchId;
    cout<<"Enter The ID you want to search: ";
    cin>>searchId;
    int resultIndex=searchPerson(people, ARRAY_SIZE, searchId);
    if (resultIndex!=-1) {   //ពិនិត្យលទ្ធផលនៃការស្វែងរក
        cout<<"\nSuccess! Person Found at index: "<<resultIndex<<":"<<endl;
        outputPerson(people[resultIndex]);
    }
    else {
        cout<<"\nError: Person with ID"<<searchId<<"Was not found!"<<endl;
    }
    return 0;
}