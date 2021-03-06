#include<iostream>
#include<string>
using namespace std;
struct date{
	int year;
	int month;
	int day;
};

struct Person{
	string name;
	int age;
	bool gender;
	date birth;
	Person(){
		age = 18;
		cout<<"创建Person对象"<<this<<endl;
	}
	~Person(){
		cout<<"释放Person对象"<<this<<endl;
	}
	

};

class autodelete{
	Person* p;
	int cnt;
	public:
	autodelete(Person *person):cnt(1){
		p = person;
	}
	autodelete(const autodelete &per):p(per.p){cnt++;cout<<cnt<<endl;}
	~autodelete(){
		delete p;//调用结构体的析构函数
	}
	//重载"->"运算符，返回指针
	Person* operator->(){
		return p;
	}
	//重载“*”运算符，返回*p
	Person& operator*()
	{
		return *p;
	}
};

int main()
{
	autodelete a = new Person;
	autodelete b = a;
	autodelete c = a;
	cout<<a->age<<endl;
	a->birth.year = 1992;
	cout<<(*a).birth.year<<endl;
	return 0;
}
