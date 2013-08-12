#include<iostream>
using namespace std;

class Fraction{
	int n;
	int d;
	public:
	Fraction(int n=0, int d=1):n(n), d(d){}
	friend istream &operator>>(istream &in, Fraction &f);
	friend ostream &operator<<(ostream &out, Fraction &f);
};

istream &operator>>(istream &in , Fraction &f)
{
	char c;
	in>> f.n >> c >> f.d;
	return in;
}

ostream &operator<<(ostream &out, Fraction &f)
{
	out<< f.n << '/' << f.d << endl;
	return out;
}


int main()
{
	Fraction f;
	cin>>f;
	cout<<f;
	return 0;
}
