#include<iostream>
using namespace std;

#define DF(N) void N(){cout<<"function "#N"called..."<<endl;}

DF(a); DF(b);DF(c);DF(d);DF(e);DF(f);DF(g);

void(*func_tab[])() = {a, b, c, d, e, f, g};

int main()
{
	while(1){
	cout<<"press a key form 'a' to 'g'""or q to quit"<<endl;
	char c;
	cin>>c;
	if(c=='q');
		break;
	if(c<'a'||c>'g')
		continue;
	(*func_tab[c-'a'])();
	}
	return 0;
}
