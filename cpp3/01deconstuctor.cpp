#include<iostream>

using namespace std;
class F{
	int n;
	int d;
	public:
		F(int n=0, int d=1);
		F(const F &a):n(a.n), d(a.d){cout<<"F(const F &)"<<endl;};//拷贝构造函数
		//如果定义拷贝构造参数，编译器会自动产生一个拷贝构造参数，逐个拷贝成员值
		void print(bool newline=true);
		void print(bool newline=true)const;//const指的是对象自身,数据不能修改
		//成员函数中，有cosnt和没const构成重载
		~F();
};

F::F(int n, int d):n(n), d(d)
{
	cout<<this<<"; constructor:(" << n << "/" << d << ")"<<endl;
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

F function(F f)
{
	return f;
}

F::~F()
{
	cout<<this<<"; destructor:(" << n << "/" << d << ")"<<endl;
}
int main()
{
	/*F a(2,3);
	F b;
	a.print();
	b.print();
	cout<<&a<<endl;
	cout<<&b<<endl;
	compare(a, b);
	*/
	
	F a;
	function(a);
	/**output
	0xbfad86b8; constructor:(0/1)
	F(const F &)
	F(const F &)
	0xbfad86c0; destructor:(0/1)//返回值
	0xbfad86c8; destructor:(0/1)//形参析构
	0xbfad86b8; destructor:(0/1)//实参析构
	*/
	return 0;
}
