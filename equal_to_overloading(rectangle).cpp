#include"rectangle.h"
bool Rectangle::operator==(Rectangle &r) {
    if (width_+length_==r.width_+r.length_) {
        return true;
    }else {
        return false;
    }
}
int main() {
    Rectangle r1(15.1,25.2),r2(15.1,25.2);
    if (r1==r2) {
        cout<<"\n\tRectangle 1 is equal to rectangle 2\n\n";
    }else {
        cout<<"\n\tRectangle 1 is not equal to rectangle 2\n\n";
    }
    return 0;
}