#include<iostream>

using namespace std;
//io对象要求能转换成bool类型。对处于正常状态的io对象转成true，对处于错误状态的io对象转成falsiiiiie

//处于错误状态的io对象拒绝执行io操作，。clear()只清除错误状态，但不清除缓冲区，这样此io对象可以继续执行io操作

//.eof(), .fail(), .bad(), .good()

int main()
{
	cout << "cin = " << cin << endl;
	cout << cout <<endl;
	int n;
	cin >> n;
	cout << "cin = " << cin << endl;
	string str;
	cin >> str;
	cout << "str = " << str << endl;

return 0;
/*正常输入
cin = 0x6020b0
0x6021c8
55
cin = 0x6020b0
*/

/*错误输入
cin = 0x6020b0
0x6021c8
dd
cin = 0
*/
}
