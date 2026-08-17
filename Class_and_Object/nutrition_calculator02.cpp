#include<iostream>
#include<string>
#include<iomanip>  //មានមុខងារ setfill,setw។ល។
using namespace std;
class PersonProfile {
private:
    char sex=0;
    double height=0;
    double weight=0;
    int age=0;
    int activityLevel=1;
    public:
    PersonProfile() {
        sex='M';
        height=0;
        weight=0;
        age=0;
        activityLevel=1;
    }
    PersonProfile(char seX,double heighT , double weighT, int agE, int activityLeveL) {
        sex=seX;
        height=heighT;
        weight=weighT;
        age=agE;
        activityLevel=activityLeveL;
    }
    char getSex() const {
        return sex;
    }
    double getHeight() const {
        return height;
    }
    double getWeight() const {
        return weight;
    }
    int getAge() const {
        return age;
    }
    int getActivityLevel() const {
        return activityLevel;
    }
    void displayPersonProfile() {
        cout<<"Sex: "<<sex<<", Height: "<<height<<"m, Weight: "<<weight<<"kg, Age: "<<age<<", ActivityLevel: "<<activityLevel<<endl;
    }
    void setSex(char seX) {
        sex=seX;
    }
    void setHeight(double heighT) {
        height=heighT;
    }
    void setWeight(double weighT) {
        weight=weighT;
    }
    void setAge(int agE) {
        age=agE;
    }
    void setActivityLevel(int activityLeveL) {
        activityLevel=activityLeveL;
    }
    void setPersonProfile(char seX, double heighT, double weighT, int agE, int activityLeveL) {
        sex=seX;
        height=heighT;
        weight=weighT;
        age=agE;
        activityLevel=activityLeveL;
    }
    double calculateBMI() const {
        return weight/(height*height);
    }
    double calculateBMR() const {  //គណនាអត្រារំលាយអាហារមូលដ្ថាន
        double bmiBase=(10.0 * weight)+(6.25*(height*100))-(5.0*age);
        if (sex=='M'||sex=='m') {
            return bmiBase+5.0;
        }else {
            return bmiBase-161.0;
        }
    }
    double calculateTDEE()const {
        double activityMultiplier=1.2;
        switch (activityLevel) {
            case 1: activityMultiplier=1.2; break;
            case 2: activityMultiplier=1.375; break;
            case 3: activityMultiplier=1.55; break;
            case 4: activityMultiplier=1.725; break;
            case 5: activityMultiplier=1.9; break;
        }
        return calculateBMR()*activityMultiplier;
    }
    double calculateTargetCalories(int goal) const {
        double tdee=calculateTDEE();
        switch (goal) {
            case 1: return tdee-250;
            case 2: return tdee+250;
            default : return tdee;
        }
    }
    double getProtein(int goal)const {
        return (calculateTargetCalories(goal)*0.30)/4;
    }
    double getFat(int goal) const {
        return (calculateTargetCalories(goal)*0.30)/9;
    }
    double getCarb(int goal) const {
        return (calculateTargetCalories(goal)*0.40)/4;
    }
    string getBMIStatus() const {  //កំនត់ស្ថានភាពបុគ្គលផ្អែកលើសន្ទស្សន៍ម៉ាសរាងកាយ
        double bmi=calculateBMI();
        if (bmi<18.5) return"Underweight";
        else if (bmi>=18.5 && bmi<=25.0) return"Normalweight";
        else if (bmi>=25.0 && bmi<=30.0) return"Overweight";
        else return "Obese";
    }
};
void printLine() {
    cout<<setfill('-')<<setw(83)<<"-"<<setfill(' ')<<endl;
}
int main() {
    PersonProfile persons[3];
    persons[0]=PersonProfile('F',1.63,53.36,19,1);
    persons[1]=PersonProfile('M',1.71,69.96,23,1);
    cout<<"\n===PROFILE & METABOLIC METRICS==="<<endl;
    printLine();
    cout<<left<<setw(8)<<"Person"
        <<setw(5)<<"Sex"
        <<setw(8)<<"Height"
        <<setw(8)<<"Weight"
        <<setw(5)<<"Age"
        <<setw(10)<<"BMI"
        <<setw(12)<<"BMR Status"
        <<setw(10)<<"BMR(kcal)"
        <<setw(10)<<"TDEE(kcal)"<<endl;
    printLine();
    for (int i=0; i<2; i++) {
        cout<<left<<setw(8)<<i+1
            <<setw(5)<<persons[i].getSex()
            <<setw(8)<<fixed<<setprecision(2)<<persons[i].getHeight()
            <<setw(8)<<persons[i].getWeight()
            <<setw(5)<<persons[i].getAge()
            <<setw(10)<<persons[i].calculateBMI()
            <<setw(12)<<persons[i].getBMIStatus()
            <<setw(10)<<persons[i].calculateBMR()
            <<setw(10)<<persons[i].calculateTDEE()<<endl;
    }
    printLine();
    cout<<"\n===NUTRITIONAL GOALS & MACROS==="<<endl;
    printLine();
    cout<<left<<setw(8)<<"Person"
    <<setw(15)<<"Goal"
    <<setw(15)<<"Target Cals"
    <<setw(15)<<"Protein(g)"
    <<setw(15)<<"Fat(g)"
    <<setw(15)<<"Carbs(g)"<<endl;
    printLine();
    for (int i=0;  i<2;i++) {
        cout<<left<<setw(8)<<i+1
            <<setw(15)<<"Weight Loss"
            <<setw(15)<<persons[i].calculateTargetCalories(1)
            <<setw(15)<<persons[i].getProtein(1)
            <<setw(15)<<persons[i].getFat(1)
            <<setw(15)<<persons[i].getCarb(1)<<endl;
        cout<<left<<setw(8)<<i+1
            <<setw(15)<<"Weight Gain"
            <<setw(15)<<persons[i].calculateTargetCalories(2)
            <<setw(15)<<persons[i].getProtein(2)
            <<setw(15)<<persons[i].getFat(2)
            <<setw(15)<<persons[i].getCarb(2)<<endl;
        if (i==0) {
            cout<<endl;
        }
    }
    printLine();
    return 0;
}