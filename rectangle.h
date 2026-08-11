#include<iostream>
using namespace std;
class Rectangle {
private:
    float width_;
    float length_;
public:
    Rectangle(float w=0, float l=0): width_(w), length_(l) {}
    void show() {
        cout<<"\n\tWidth: "<<width_<<", Length: "<<length_<<"\n\n";
    }
    Rectangle operator+(Rectangle &r2);
    bool operator==(Rectangle &r);
    void operator=(Rectangle &r);
};