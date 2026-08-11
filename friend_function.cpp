#include<iostream>
using namespace std;
class Cla {
    private:
    string prop;
public:
    Cla(string proP) {
        prop=proP;
    }
    friend void met();
};
void met() {
    Cla cla("\n\tOutside function can use property of class Cla.\n");
    cout<<cla.prop<<endl;
}
int main() {
    met();
}