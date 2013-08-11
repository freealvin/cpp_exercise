#include<iostream>

using namespace std;
class F{
	int n;
	int d;
	public:
		F(int n=0, int d=1);
		void print(bool newline=true);
		void print(bool newline=true)const;//const指的是对象自身,数据不能修改
		//成员函数中，有cosnt和没const构成重载
		~F();
};

F::F(int n, int d):n(n), d(d)
{
	cout<<"constructor:(" << n << "/" << d << ")"<<endl;
}

void F::print(bool newline)
{
	cout<< n << "/" << d;
	if(newline) cout <<endl;
}
void F::print(bool newline) const
{
	cout<< "readonly: " << n << "/" << d;
	if(newline) cout <<endl;
}

void compare(const F &a, F &b)
{
	a.print();//cout<<"&a"<<&a<<endl;
	b.print();//cout<<"&b"<<&b<<endl;
}

F::~F()
{
	cout<<"destructor:(" << n << "/" << d << ")"<<endl;
}
int main()
{
	const F a(2,3);
	F b;
	a.print();
	b.print();
	cout<<&a<<endl;
	cout<<&b<<endl;
	compare(a, b);
	return 0;
}
