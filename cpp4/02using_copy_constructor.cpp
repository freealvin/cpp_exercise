#include<iostream>
#include<string>

using namespace std;
typedef string T;

class Stack{
	typedef unsigned int uint;
	T* mem;
	uint len;
	uint max;
	public:
		Stack(const Stack &t):mem(new T[t.max]), len(t.len), max(t.max){}
		Stack(uint n):mem(new T[n]), max(n), len(0){}
		Stack & push(T t){
			if(len>=max)
				throw 0;
			if(len<max)
				mem[len++] = t;
			return *this;
		}

		T pop(){
			if(len>0)
				return mem[--len];
			else
				throw 0;
		}

		void print()
		{
			cout<<"len:"<<len<<endl;
			for(uint i=0;i<len;i++)
				cout<<i<<":"<<mem[i]<<" ";
		}

		~Stack(){
			delete[] mem;
		}
};

int main()
{
	Stack t(5);
	Stack t2(t);
	t.push("1").push("2");
	t.print();
	cout<<endl;
	return 0;
}
