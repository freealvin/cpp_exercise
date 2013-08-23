#include<iostream>
#include<string>
using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{
	double real;
	double imagine;
	public:
		Complex(double r=0, double i=0):real(r), imagine(i){}
		Complex operator+(const Complex &c2)const;
		Complex operator*(const Complex &c2)const;
		Complex operator/(const Complex &c2)const;
		operator bool()const;
		operator string()const;
		friend ostream& operator<<(ostream &o, const Complex &ci);
		
		~Complex(){}
};
#endif
