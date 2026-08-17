#include"rectangle.h"
void Rectangle::operator=(Rectangle &r) {
    cout<<"\n\n\tWidth: "<<width_<<" Length: "<<length_<<"\n\n";
}
int main() {
    Rectangle r(15.1,25.2);
    r=r;
    return 0;
}