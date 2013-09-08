#include<iostream>
#include<string>

using namespace std;

// i.putback(字符)
// i.peek() 不取走下个字符

int main()
{
	char buf[100];
	char c;
	
	cin >> ws; //跳过空格widescape
	cin.get(c);
	cin.putback(c);

	if(isdigit(c)){
		double d;
		cin >> d;
		cout << "d = " << d << endl;
	}else
	{
		string s;
		cin >> s;
		cout << "s =" << s << endl;
		
	}


	cin >> ws;

	if(cin.peek()>='0'&&cin.peek()<='9'){//peek查看缓冲区第一个字符
		double d;
		cin >> d;
		cout << "d = " << d << endl;
	}else
	{
		string s;
		cin >> s;
		cout << "s =" << s << endl;
		
	}


	return 0;
}
