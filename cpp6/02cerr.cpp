#include<iostream>

using namespace std;
//缓冲遇到换行、有熟人、满、程序结束、flush会刷新
//
int main()
{
	cout << "Hello" ;//缓冲，可重定向
	cerr << "World" ;// 无缓冲，不可重定向
	clog << "Alvin" ;//理论上缓冲不可重定向，实际无缓冲
	return 0;
}
