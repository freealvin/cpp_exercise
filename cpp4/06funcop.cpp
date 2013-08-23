#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef unsigned int uint;
class A{
	int *p;
	uint n;
	public:
		A(int n):n(n){
			p = new int[n];
			if(p==NULL)
				throw 0;
			memset(p, 0, 4*n);
		}

		~A(){
			delete [] p;
		}

		uint size()const{return n;}
		int& operator[](uint i)const{
			if(i>=n) throw 0;
			return p[i];
		}
		int& operator[](const char *c)const{
			int i = atoi(c);
			if(i<0||i>=n)throw 1;
			return p[i];
		}
		
		A& operator()(int beg, int delta)
		{
			for(uint i=0;i<n;i++)
				p[i] = beg, beg += delta;
			return *this;
		}

};

ostream& operator<<(ostream &o,const A & a)
{
	o<<"{ ";
	for(uint i=0;i<a.size();i++)
		o<<a[i]<<' ';
	o<<"}";
	return o;
}

int main()
{
	A a(4);
	a[3] = 3;
	cout<< a<<endl;
	a["a"] = 20;
	cout<<a<<endl;
	cout<<"a:"<<a(10, 1)<<endl;
	/*
 *
 *{ 0 0 0 3 }
 *{ 0 0 20 3 }
 * */
	return 0;
}
