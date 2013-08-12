#include<iostream>
using namespace std;

class Fraction{
	int n;
	int d;
	public:
	Fraction(int n=0, int d=1):n(n), d(d){}
	const Fraction operator+(const Fraction &f)const;
	friend istream &operator>>(istream &in, Fraction &f);
	friend ostream &operator<<(ostream &out, Fraction &f);
};

//求最大公约数
int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}
//作为函数成员，重载+运算符
const Fraction Fraction::operator+(const Fraction &f)const
{
	Fraction fra;
	fra.n = (f.n)*d + n*(f.d);
	fra.d = d* (f.d);
	int m = gcd(fra.n, fra.d);
	fra.n /= m;
	fra.d /= m;
	cout<<(fra.n)<<'/'<<(fra.d)<<endl;
	return fra;
}
//重载>>，以便于输入
istream &operator>>(istream &in , Fraction &f)
{
	char c;
	in>> f.n >> c >> f.d;
	return in;
}
//重载<<，便于输出
ostream &operator<<(ostream &out, Fraction &f)
{
	out<< f.n << '/' << f.d << endl;
	return out;
}


int main()
{
	Fraction f1;
	Fraction f2;
	cin>>f1>>f2;
	cout<<f1<<f2;
	//cout<<(f1+f2);
	return 0;
}
