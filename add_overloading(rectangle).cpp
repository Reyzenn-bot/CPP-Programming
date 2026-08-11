#include"rectangle.h"
Rectangle Rectangle::operator+(Rectangle &r2) {
    Rectangle r3;
    r3.width_=this->width_+r2.width_;
    r3.length_=this->length_+r2.length_;
    return r3;
}
int main() {
    Rectangle r1(15.1,25.2),r2(25.2,35.3),r3=r1+r2;
    r3.show();
    return 0;
}