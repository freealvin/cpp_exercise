#include<iostream>
using namespace std;

class Fraction{
	int n;
	int d;
	void reduce()
	{
		int m = maxgcd(n, d);
		if(m!=1)
		{
			n = n/m;
			d = d/m;
		}
	}


	public:
		//求最大公约数
		static int maxgcd(int a, int b)
		{
			if(b==0) return a;
			return maxgcd(b, a%b);
		}
		Fraction(int n=0, int d=1):n(n), d(d){
			if(d<0) d=-d, n=-n;
			reduce();
		}
		Fraction operator+( const Fraction &f2)const;
		friend istream &operator>>(istream &in, Fraction &f);
		friend ostream &operator<<(ostream &out,const Fraction &f);
};



Fraction Fraction::operator+( const Fraction &f2)const
{
	Fraction res(n*f2.d + d*f2.n, d*f2.d);
	return res;
}

//重载>>，以便于输入
istream &operator>>(istream &in , Fraction &f)
{
	char c;
	in>> f.n >> c >> f.d;
	return in;
}
//重载<<，便于输出
ostream &operator<<(ostream &out, const Fraction &f)//f should not be non-const referenc
{
	out<< f.n << '/' << f.d;
	return out;
}


int main()
{
	Fraction f1;
	Fraction f2;
	cin>>f1>>f2;
	cout<<f1<<','<<f2<<endl;
	cout<<f1+f2<<endl;//temp f1+f2, operator<<(cout, temp), it's not allowed to bind the temporary value to a non-const reference
	return 0;
}
