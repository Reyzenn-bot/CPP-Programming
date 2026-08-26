#include<iostream>
#include<exception>
using namespace std;
double divide(double dividend, double divisor) {
    if (divisor==0) {
        throw invalid_argument("Division by zero is not allowed.");
    }
    return dividend / divisor;
}
int main() {
    try {
        cout<<divide(5.5,0);
        cout<<divide(10.5,3.1);
    }
    catch (const invalid_argument& e) {
        cerr<<"Argument error: "<<e.what()<<endl;
    }
    catch (const exception& e) {
        cerr<<"Standard exception: "<<e.what()<<endl;
    }
    catch (...) {
        cerr<<"Unknown exception occurred.\n";
    }
    return 0;
}