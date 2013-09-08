#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

//i.getline(char 数组, 数组大小) 数组大小保证不会越界;如果不能读完一整行会设置错误状态
//getline(i对象,string对象引用), 不是成员函数，而是全局函数
int main()
{
	char buf[10];
	if(!cin.getline(buf, sizeof(buf)))
	{
		cout << "缓冲区不够大" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	string s;
	//getline(cin, s);//可以加第三个参数，表示读到那个字符为止, 默认是换行符'\n'
	getline(cin, s, '~');

	//可以用来读格式化文件key value
	
	
	cout << buf << endl;
	cout << s << endl;
	printf("%s", s.c_str());//string 转 c风格字符串

	return 0;
}
