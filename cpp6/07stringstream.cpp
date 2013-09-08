#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
	string s = "1234 4.5 x hello 120 100";
	int a, d, e;
	double b;
	char c;
	char buf[100];
	
	istringstream is(s);
	is >> a >> b >> c >> buf >> oct >> d >> hex >> e;
	
	cout << "a = " << a <<  ", b = " << b << ", c=" << c << ", buf = " << buf  <<" , d=" << d << ", e=" << e << endl;

	cout << "******************************************" << endl;
	ostringstream os;
	os << "a = " << a <<  ", b = " << b << ", c=" << c << ", buf = " << buf  <<" , d=" << d << ", e=" << e << endl;
	//cout<< s.str() << endl;
	
	cout << os.str();
	cout << "******************************************" << endl;
	return 0;
}
