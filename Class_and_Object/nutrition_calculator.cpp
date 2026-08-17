#include<iostream>
#include<string>
using namespace std;
class PersonProfile {
private:
    char sex=0;
    double height=0;
    double weight=0;
    int age= 0;
    int activtyLevelel=1;
public:
    PersonProfile() {
        sex='M'; height=0; weight=0; age=0; activtyLevelel=1;
    }
    PersonProfile(char seX, double heighT, double weighT, int agE, int activtyLeveL) {
        sex=seX;
        height=heighT;
        weight=weighT;
        age=agE;
        activtyLevelel=activtyLeveL;
    }
    char getSex() const{ return sex;}
    double getHeight() const{ return height;}
    double getWeight() const{ return weight;}
    int getAge() const{ return age;}
    int getActivtyLevelel() const{ return activtyLevelel;}
    void displayPersonProfile() {
        cout<<"Sex: "<<sex<<", height: "<<height<<"m, weight: "<<weight<<"kg, Age: "<<age<<", ActivityLevel: "<<activtyLevelel<<endl;
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
    void setActivtyLevelel(int activtyLeveL) {
        activtyLevelel=activtyLeveL;
    }
    void setPersonProfile(char seX, double heighT, double weighT, int agE,int activityLeveL) {
        sex=seX;
        height=heighT;
        weight=weighT;
        age=agE;
        activtyLevelel=activityLeveL;
    }
    double calculateBMI() const {
        return weight/(height*height);
    }
    double calculateBMR() const {
        //កម្ពស់គុណនឹង១០០ដើម្បីដូរខ្នាតពិម៉ែត្រទៅសង់ទីម៉ែត្រ
        double bmrBase = (10.0 * weight) + (6.25 * (height*100)) - (5.0 * age);
        if (sex =='M' || sex =='m') {
            return bmrBase+5;
        }
        else {
            return bmrBase-161.0;
        }
    }
    double calculateTDEE() const {
        double activtyMultiplier=1.2;
        switch (activtyLevelel) {
            case 1: activtyMultiplier=1.2; break;
            case 2: activtyMultiplier=1.375; break;
            case 3: activtyMultiplier=1.55; break;
            case 4: activtyMultiplier=1.725; break;
            case 5: activtyMultiplier=1.9; break;
                ; break;
        }
        return calculateBMR()*activtyMultiplier;
    }
    double calculateTargetCalories(int goal) const {
        double tdee=calculateTDEE();
        switch (goal) {
            case 1: return tdee-250;
            case 2 : return tdee+250;
            default : return tdee;
        }
    }
    void displayRequiredMacro(int goal) const {
        double protein = 0, fat=0, carb=0;
        double targetCalories=calculateTargetCalories(goal);
        protein=(targetCalories*0.30)/4.0;
        fat=(targetCalories*0.30)/9.0;
        carb=(targetCalories*0.40)/4.0;
        string goalText="";
        if (goal==1) goalText= "of weight loss";
        else if (goal==2) goalText="of weight gain";
        else goalText="of maintenance";
        cout<<"Required > Protein: "<<protein<<"g, Fat: "<<fat<<"g, and carbs: "<<carb<<"g "<<goalText<<endl;
    }
};
int main() {
    PersonProfile persons[3];
    persons[0]=PersonProfile('F', 1.63,53.36,19,1);
    persons[0].displayPersonProfile();
    cout<<"BMI: "<<persons[0].calculateBMI()<<endl;
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
    cout<<"BMR: "<<persons[1].calculateBMR()<<endl;
    cout<<"TDEE: "<<persons[1].calculateTDEE()<<endl;
    cout<<"Weight loss goal: "<<persons[1].calculateTargetCalories(1)<<"kcal"<<endl;
    persons[1].displayRequiredMacro(1);
    cout<<"Weight gain goal: "<<persons[1].calculateTargetCalories(2)<<"kcal"<<endl;
    persons[1].displayRequiredMacro(2);
    return 0;
}