#include<iostream>

using namespace std;
//.get() .put() .ignore() .getline()
int main()
{
	int n = cin.get();//相当于c中的getchar()
	char b, c, d;
	cin.get(b).get(c).get(d);
	//如果输入为7bcEnter
	//那么n为7的ASII码值， d为换行符
	//
	//如果输入为 7bcde
	//d的值为'd'
	cout << n << ',' << c << ',' << b << ',' << d << endl;

	cin.ignore(200, '\n');//忽略多余的输入直到'\n'，'\n'也被忽略

	char e;
	cin >> e;//cin有缓冲，如果在上次输入时有未用到的字符可以继续作为输入
	cout << e << endl;
	
	//cin会跳过空白字符，get不会跳过
	return 0;
}
