#include<iostream>

using namespace std;
//io对象要求能转换成bool类型。对处于正常状态的io对象转成true，对处于错误状态的io对象转成falsiiiiie
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
