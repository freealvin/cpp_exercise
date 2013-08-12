#include<iostream>
using namespace std;
class Array{
	int len;
	char a[100];
	mutable int cur;//mutable means cur can be changed
	public:
	Array():len(0),cur(0){}
	char first()const{ cur=0; return len>=1?a[0]:' ';}
	char next()const{return a[++cur];}//cur change, although in const object
	bool hasnext() const;
	void add(char c);
	void add(const char* s){
		while(*s)
			add(*s++);

	}
	void remove(int pos){
		if(pos<0||pos>len) return;
		pos--;
		while(pos<len-1){
			a[pos] = a[pos+1];
			pos++;
		}
		len--;
	}
};

void Array::add(char c){
	a[len++] = c;
}
bool Array::hasnext()const{
	//cout<<cur<<':'<<len<<endl;
	return cur<len-1;
}
void show(const Array &a)
{

	cout<<a.first()<<' ';
	while(a.hasnext())
		cout<<a.next()<<' ';
	cout<<endl;
}

int main()
{
	Array a;
	a.add("hello");
	a.add("world");
	show(a);
	a.remove(3);
	show(a);
	return 0;
}


