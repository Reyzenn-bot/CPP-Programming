#include<iostream>
#include<string>
using namespace std;
class Person {
private:
    string name;
    int age;
    char gender;
    float weight;
    float height;
    int activity;
    float bmi;
    float bmr;
    float tdee;
    float protein;
    float carb;
    float fat;
    string goal;
    float targetCalories;
public:
    Person() {
        name="";
        age=0;
        gender=' ';
        weight=0.0;
        height=0.0;
        activity=0;
        tdee=0.0;
        protein=0.0;
        carb=0.0;
        fat=0.0;
        goal="";
        targetCalories=0.0;
    }
    Person(string name,int age, char gender, float weight, float height, int activity) {
        this->name=name;
        this->age=age;
        this->gender=gender;
        this->height=height;
        this->weight=weight;
        this->activity=activity;
        this->bmi=0.0;
        this->bmr=0.0;
        this->tdee=0.0;
        this->targetCalories=0.0;
        this->protein=0.0;
        this->fat=0.0;
        this->carb=0.0;
        this->goal="";
    }
    string getname() const {
        return name;
    }
    int getAge() const{
        return age;
    }
    char getGender() {
        return gender;
    }
    float getWeight() const {
        return weight;
    }
    float getHeight() const {
        return height;
    }
    void UserInput() {
        cout<<"Enter your name: "<<endl;
        getline(cin,name);
        cout<<"Enter your age: "<<endl;
        cin>>age;
        cout<<"Enter your gender: "<<endl;
        cin>>gender;
        cout<<"Enter your weight: "<<endl;
        cin>>weight;
        cout<<"Enter your height: "<<endl;
        cin>>height;
        cout<<"1. Sedentary."<<endl;
        cout<<"2. Lightly Active."<<endl;
        cout<<"3. Moderately Active."<<endl;
        cout<<"4. Very Active."<<endl;
        cout<<"5. Extra Active."<<endl;
        cout<<"Enter your activity level (1-5): "<<endl;
        cin>>activity;
    }
    void BMICalculate() {
        bmi=weight/(height*height);
    }
    void BMRCalculate() {
        if (gender=='m'||gender=='M') {
            bmr= (10 * weight)+(6.25*height*100)-(5*age)+5;
        }else if (gender=='f'||gender=='F') {
            bmr = (10 * weight)+(6.25*height*100)-(5*age)-161;
        }
    }
    void TDEECalculate() {
        float multiplier=0.0;
        if (activity==1) {
            multiplier=1.2;
        }else if (activity==2) {
            multiplier=1.375;
        }else if (activity==3) {
            multiplier=1.55;
        }else if (activity==4) {
            multiplier=1.725;
        }else if (activity==5) {
            multiplier=1.9;
        }
        tdee=bmr*multiplier;
    }
    void MicronutrientsCalculate() {
        protein=(targetCalories * 0.30) / 4;
        fat=(targetCalories * 0.30) / 9;
        carb=(targetCalories * 0.40) / 4;
    }
    void GoalCalculate() {
        if (bmi>24.9 && bmi<29.9) {
            targetCalories=tdee-250;
            goal="Weight Loss";
        }else if (bmi<18.5) {
            targetCalories=tdee+250;
            goal="Weight Gain";
        }else if (bmi>18.5 && bmi<24.9) {
            targetCalories=tdee;
            goal="Weight Maintenance";
        }
    }
    void UserOutput() const{
        if (bmi<18.5) {
            cout<<"Your BMI is: "<<bmi<<" is under weight"<<endl;
        }else if (bmi>18.5 && bmi<24.9) {
            cout<<"Your BMI is: "<<bmi<<" is normal weight"<<endl;
        }else if (bmi>24.9 && bmi<29.9) {
            cout<<"Your BMI is: "<<bmi<<" is over weight"<<endl;;
        }else if (bmi>30) {
            cout<<"Your BMI is: "<<bmi<<" is obese"<<endl;
        }
        cout<<"Your BMR is: "<<bmr<<"kcal"<<endl;
        cout<<"Your Today Daily Energy Expenditure is: "<<tdee<<"kcal"<<endl;
        cout<<"Your Goal is: "<<goal<<endl;
        cout<<"Your Target Calories is: "<<targetCalories<<"kcal"<<endl;
        cout<<"Your Protein Needed is: "<<protein<<"g"<<endl;
        cout<<"Your Fats Needed is: "<<fat<<"g"<<endl;
        cout<<"your Carbohydrates Needed is: "<<carb<<"g"<<endl;
    }
};

int main() {
    Person person;
    person.UserInput();
    person.BMICalculate();
    person.BMRCalculate();
    person.TDEECalculate();
    person.GoalCalculate();
    person.MicronutrientsCalculate();
    person.UserOutput();
    return 0;
}