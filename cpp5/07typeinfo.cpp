#include <iostream>

#include <typeinfo>

using namespace std;

class A
{
	public:
		virtual void f(){}
};

class B : public A{};

class C : public B{};

class D : public A{};

int main()
{
	A *p1 = new A, *p2 = new B, *p3 = new C, *p4 = new D, *p5 = NULL;
	cout << typeid(*p1).name() << endl;
	cout << typeid(*p2).name() << endl;
	cout << typeid(*p3).name() << endl;
	cout << boolalpha << (typeid(*p2)==typeid(*p3)) << endl;
	
	const type_info& t = typeid(*p4);
	cout << t.name() << endl;	
	delete p1;delete p2;delete p3;delete p4;delete p5;
	return 0;
}
