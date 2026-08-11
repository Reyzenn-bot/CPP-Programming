#include <iostream>
using namespace std;
class V;
class U {
    private:
    string attr;
    public:
    U(string attR) {
        this->attr=attR;
    }
    void method1inU();
    void method2inU();
};
class V {
    private:
    string prop;
    public:
    V(string proP) {
        prop=proP;
    }
    friend void U::method1inU();
};
void U::method1inU() {
    V v("property of class V.\n");
    cout<<"\n\tMethod 1 in class U uses"<<v.prop<<"\n";
}
void U::method2inU() {
    cout<<"\tMethod 2 uses"<<attr<<'\n';
}
int main() {
    U u("attribute of class U.\n");
    u.method1inU();
    u.method2inU();
}
