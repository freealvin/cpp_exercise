/*多态:指针调用虚函数
 * 子类实例对象的地址，赋值给指向父类的指针
 * 指针调用函数时，根据对象调用子类相应的函数
 * 注意：
 * 	实现多态的函数，父类要把函数定义为virtual类型（虚函数）
 *
 * */

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
		virtual void show(){//加上virtual后实现指针调用时根据对象调用函数
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
			cout<<name<<"老师在给"<<_class<<"讲"<<course<<endl;
		}

		Teacher(const char* name, bool gender, const char *course):Person(name, gender),course(course)
		{

		}
		
		void show()//隐藏重写父类的成员函数,会覆盖父类的成员函数
		{
			cout<<"同学们好,我是老师"<<name<<",希望在今后的教学里，和大家一起学习"<<course<<endl;
		}
};

int main()
{
	Person a("alvin", false);
	Teacher b("nathan", true, "C++");
	
	Person *p = NULL, *q = NULL;
	p = &a;
	p->show();
	q = &b;
	q->show();

	Person c = b;
	Person &d = b;
	cout<< dynamic_cast<Teacher*>(p) <<endl;
	cout<< dynamic_cast<Teacher*>(q) <<endl;

	cout<< dynamic_cast<Teacher*>(&c) <<endl;
	cout<< dynamic_cast<Teacher*>(&d) <<endl;
	//dyanmic_cast使用时，基类必须包含virtual函数，虚函数
	//否则编译时出现：(source type is not polymorphic)
	
	//dynamic_cast<子类 *>(子类或父类的地址)检查能否转换成子类
	//如果不可以返回NULL，可以返回地址
	//0
	//0x7fff3097ee10
	//0
	//0x7fff3097ee10
	return 0;
}
