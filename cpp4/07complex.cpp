#include <iostream>
#include <string>
#include <sstream>
#include "07complex.h"
using namespace std;

Complex Complex::operator+(const Complex & c2)const
{
	Complex tem(real+c2.real, imagine+c2.imagine);
	return tem;
}

ostream& operator<<(ostream &o, const Complex &c)
{
	o<< c.real<< ' ' <<(c.imagine>0?'+':'-') << ' ' <<(c.imagine>0?c.imagine:(-c.imagine)) <<'i';
	return o;
}

Complex Complex::operator*(const Complex &c2)const
{
	Complex tmp(real*c2.real + imagine*c2.imagine, real*c2.imagine+imagine*c2.real);
	return tmp;
}


Complex Complex::operator/(const Complex &c2)const
{
	double r = real*c2.real + imagine*c2.imagine;
	double i = imagine*c2.real - real*c2.imagine;
	double t = c2.real*c2.real + c2.imagine*c2.imagine;
	//cout<<r<<":"<<i<<endl;
	Complex tmp(r/t, i/t);
	return tmp;
}

Complex::operator bool()const
{
	return real||imagine;
}

Complex::operator string()const
{
	stringstream sStream;
	string str="";
	sStream<<real;
	if(imagine>0)
		sStream<< '+';
	sStream<<imagine;
	sStream<< 'i';
	str = sStream.str();
	cout<<str<<endl;
	return str;
}
