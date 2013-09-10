#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student{
    string name;
    bool gender;
    double grade;
    public:
        Student(string name="佚名", bool gender=false, double grade=0.0);
        bool add();
        Student search(string name);

};

Student::Student(string name, bool gender,double grade):name(name), gender(gender),grade(grade){}

Student::add(){

}

int main(){}
