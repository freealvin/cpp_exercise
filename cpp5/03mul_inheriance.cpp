#include<iostream>
using namespace std;

class Goods{
	double price;
	public:
		Goods(double price):price(price){
			cout<<"Goods 构造函数"<<endl;
		}
		double getPrice(){
			return price;
		}
};
class Camera: public Goods{
	public:
		void take(const char* obj){
			cout<<"给"<<obj<<"照相"<<endl;
		}	
		Camera(double price):Goods(price)
		{
			cout<<"Camera constructor"<<endl;
		}

		~Camera()
		{
			cout<<"Camera destructor"<<endl;
		}
};

class MP3: public Goods{
	public:
		void play(const char * song){
			cout<<"播放歌曲<<"<<song<<">>"<<endl;
		}
		MP3(double price):Goods(price)
		{
			cout<<"MP3 constructor"<<endl;
		}

		~MP3()
		{
			cout<<"MP3 destructor"<<endl;
		}
};

class Phone: public Goods{
	public:
		void dial(const char* no){
			cout<<"给"<<no<<"打电话"<<endl;
		}

		Phone(const char *factory, double price):Goods(price)
		{
			cout<<"Phone cnstructor, made in"<<factory<<endl;
		}

		~Phone()
		{
			cout<<"Phone destructor"<<endl;
		}
};


class ModernPhone : public MP3, public Camera, public Phone
{
	public:
		void visitnet(const char *url){
			cout<<"访问"<<url<<endl;
		}

		ModernPhone(const char* factory, double price):Phone(factory,price), MP3(price), Camera(price)
		{
			cout<<"made in "<<factory<<endl;
		}

		~ModernPhone()
		{
			cout<<"报销"<<endl;
		}
};


int main()
{
	ModernPhone mp("china", 300);
	mp.dial("120");
	mp.take("trees");
	mp.play("i want it that way");
	mp.visitnet("www.google.com");
	mp.getPrice();
	//
	//03mul_inheriance.cpp:90:5: 错误：对成员‘getPrice’的请求有歧义
	//03mul_inheriance.cpp:10:10: 错误：备选为： double Goods::getPrice()
	//03mul_inheriance.cpp:10:10: 错误：         double Goods::getPrice()
	//03mul_inheriance.cpp:10:10: 错误：         double Goods::getPrice()
	//我们只需要一份price，就用到虚继承virtual
	return 0;
}
