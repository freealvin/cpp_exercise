#include<iostream>

using namespace std;

class F{
	int n;
	int d;
	public:
		F(int n=0, int d=0):n(n),d(d){}
		friend ostream& operator<<(ostream &o, const F&f);
		F& operator++()
		{
			n += d;
			return *this;
		}
		F operator++(int)//哑元
		{
			F old(*this);
			n += d;
			return old;			
		}
		friend F& operator--(F &f)
		{
			f.n -= f.d;
			return f;
		}
		friend F operator--(F &f,int)
		{
			F old(f);
			f.n -= f.d;
			return old;
		}
};

ostream&  operator<<(ostream &o, const F &f)
{
	o<< f.n << '/' << f.d ;
	return o;
}

int main()
{
	F f1(2,4);
	F f2(4,9);
	cout<<f2<<','<<f1<<endl;
	cout<<++f1<<endl;
	cout<<f2++<<endl;
	cout<<f2<<endl;
	cout<<f2--<<endl;
	cout<<f2<<endl;
	cout<<--f1<<endl;
	return 0;
}
