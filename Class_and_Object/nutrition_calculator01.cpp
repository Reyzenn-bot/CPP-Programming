#include <cmath>
#include<iostream>
#include<string>
#include<iomanip>
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
    double calculateBMR() const {
        //កម្ពស់គុណនឹង១០០ដើម្បីដូរខ្នាតពិម៉ែត្រទៅសង់ទីម៉ែត្រ
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
            case 1: return tdee-250;  //មួយខែស្រកគីឡូប្រហែល១គ.ក
            case 2: return tdee+250;  //មួយខែឡើងគីឡូប្រហែល១គ.ក
            default : return tdee;
        }
    }
    void displayRequiredMacro(int goal)const {
        double protein=0, fat =0,carb=0;
        double targetCalories=calculateTargetCalories(goal);
        protein=(targetCalories*0.3)/4;
        fat=(targetCalories*0.3)/9;
        carb=(targetCalories*0.4)/3;
        string goalText="";
        if (goal==1) goalText="of weight loss";
        else if (goal==2) goalText="of weight gain";
        else goalText="of maintenance";
        cout<<"Required > Protein: "<<protein<<"g, Fat: "<<fat<<"g, and Carbs: "<<carb<<"g "<<goalText<<endl;
    }
    string getBMIStatus() const {
        double bmi=calculateBMI();
        if (bmi<18.5) return"Underweight";
        else if (bmi>=18.5 && bmi<=25.0) return"Normalweight";
        else if (bmi>=25.0 && bmi<=30.0) return"Overweight";
        else return "Obese";
    }
};
int main() {
    PersonProfile persons[3];
    persons[0]=PersonProfile('F', 1.63,53.36,19,1);
    persons[0].displayPersonProfile();
    cout<<"BMI: "<<persons[0].calculateBMI()<<endl;
    cout<<"BMI Status: "<<persons[0].getBMIStatus()<<endl;
    cout<<"BMR: "<<persons[0].calculateBMR()<<endl;
    cout<<"TDEE: "<<persons[0].calculateTDEE()<<endl;
    cout<<"Weight loss goal: "<<persons[0].calculateTargetCalories(1)<<"kcal"<<endl;
    persons[0].displayRequiredMacro(1);
    cout<<"Weight gain goal: "<<persons[0].calculateTargetCalories(2)<<"kcal"<<endl;
    persons[0].displayRequiredMacro(2);
    cout<<"----------------------------------------------------------------"<<endl;
    persons[1]=PersonProfile('M',1.71,69.96,23,1);
    persons[1].displayPersonProfile();
    cout<<"BMI: "<<persons[1].calculateBMI()<<endl;
    cout<<"BMI Status: "<<persons[1].getBMIStatus()<<endl;
    cout<<"BMR: "<<persons[1].calculateBMR()<<endl;
    cout<<"TDEE: "<<persons[1].calculateTDEE()<<endl;
    cout<<"Weight loss goal: "<<persons[1].calculateTargetCalories(1)<<"kcal"<<endl;
    persons[1].displayRequiredMacro(1);
    cout<<"Weight gain goal: "<<persons[1].calculateTargetCalories(2)<<"kcal"<<endl;
    persons[1].displayRequiredMacro(2);
    return 0;
}