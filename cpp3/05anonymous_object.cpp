#include<iostream>
#include<string>
using namespace std;

class Teacher{
	string name;
	string course;
	public:
	Teacher(const char* n, const char* c):name(n), course(c)
	{
		cout<<"创建"<<name<<":"<<course<<endl;
	}
	Teacher(const Teacher &t):name(t.name), course(t.course)
	{
		cout<<"复制"<<name<<":"<<course<<endl;
	}
	~Teacher()
	{
		cout<<"释放"<<name<<endl;
	}

};

int main()
{
	Teacher t1("Alvin", "linux");
	Teacher t2 = t1;
	Teacher t3 = Teacher("Nathan", "c++");
	return 0;

}
