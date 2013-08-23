#include<iostream>
#include<string>
#include"07complex.h"
using namespace std;
int main()
{
	Complex c1(2, 3);
	Complex c2(1, -2);
	Complex c3(1, 1);
	Complex c4(0, 0);
	cout<<c1+c2<<endl;
	cout<<c1*c2<<endl;
	cout<<c1/c2<<endl;
	cout<<c1/c3<<endl;
	cout<<boolalpha<<bool(c1)<<endl;
	cout<<boolalpha<<bool(c4)<<endl;
	cout<<string(c1)<<endl;
	return 0;
}
