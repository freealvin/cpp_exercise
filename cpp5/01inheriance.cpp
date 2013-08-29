#include<iostream>
#include<string>
using namespace std;

class Person{
	protected:
		string name;
	private:
		bool gender;
	public:
		void eat(const char * food){
			cout<<name<<"在吃"<<food<<endl;
		}

		void sleep();
		void show(){
			cout<<"大家好,我是"<<(gender?"帅哥":"美女")<<
			name<<";很荣幸认识你!"<<endl;
		}

		Person(const char* name, bool gender):name(name), gender(gender)
		{
		}

		string getName()const{
			return name;
		}
};

class Teacher : public Person
{
	string course;
	public:
		void teach(const char* _class){
			//cout<<getName()<<"老师在给"<<_class<<"讲"<<course<<endl;
			cout<<name<<"老师在给"<<_class<<"讲"<<course<<endl;
		}

		Teacher(const char* name, bool gender, const char *course):Person(name, gender),course(course)
		{

		}
		
		//子类成员函数如果和父类的成员函数名称相同，就会覆盖父类成员函数，即使是不同参数表
		void show()//重写父类的成员函数,会覆盖父类的成员函数
		{
			cout<<"同学们好,我是老师"<<name<<",希望在今后的教学里，和大家一起学习"<<course<<endl;
		}
};

int main()
{
	Person a("alvin", false);
	Teacher b("nathan", true, "C++");
	a.eat("cookie");
	b.eat("soup");
	a.show();
	b.show();
	b.teach("3921");

	return 0;
}
