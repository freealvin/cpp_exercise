#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	string path = "05getline.cpp.bak";
	ifstream fin(path.c_str());
	if(!fin){
		cout << "打开文件" << path << "失败" << endl;
		return 1;
	}
	//string str;
	/*
	while(getline(fin, str, '\n'))
		cout << str << endl;
	*/

	ofstream ofs("05copy");

	char ch;
	while(fin.get(ch)){
		cout << ch;
		ofs << ch;
	}

	fin.close();
	ofs.close();
	return 0;
}
