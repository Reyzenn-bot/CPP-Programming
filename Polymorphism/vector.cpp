#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void displayVector(const vector<int> &v);
int main() {
    vector<int> numbers;

    //1. push_back(data): add new element at the last one
    numbers.push_back(40);
    numbers.push_back(10);
    numbers.push_back(30);
    numbers.push_back(20);
    cout<<"---After push_back---"<<endl;
    displayVector(numbers);

    //2. size(): give the total elements
    cout<<"\ncount(size): "<<numbers.size()<<endl;

    //3. pop_back(): delete element at the last one(delete 20)
    numbers.pop_back();
    cout<<"---After pop back---"<<endl;
    displayVector(numbers);

    //4. insert(location, data): add 15 elements at index 1
    numbers.insert(numbers.begin()+1,15);
    cout<<"---After insert 15 at index 1---"<<endl;
    displayVector(numbers);

    //5. erase(location): delete element at index 2 (delete 10)
    numbers.erase(numbers.begin()+2);
    cout<<"---After erase element at 2---"<<endl;
    displayVector(numbers);

    //6. sort: sort element from small to large
    sort(numbers.begin(),numbers.end());
    cout<<"---After sort() element---"<<endl;
    displayVector(numbers);

    //7. clear(): delete all element from vector
    numbers.clear();
    cout<<"---After clear() element---"<<endl;
    cout<<"numbers of elements after clear: "<<numbers.size()<<endl;
    return 0;
}
void displayVector(const vector<int> &v) {
    cout<<"Elements of vector: [ ";
    for (int x : v) {
        cout<<x<<" ";
    }
    cout<<"]"<<endl;
}