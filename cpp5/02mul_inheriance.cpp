#include<iostream>
using namespace std;

class Camera{
	public:
		void take(const char* obj){
			cout<<"给"<<obj<<"照相"<<endl;
		}	
		Camera()
		{
			cout<<"Camera constructor"<<endl;
		}

		~Camera()
		{
			cout<<"Camera destructor"<<endl;
		}
};

class MP3{
	public:
		void play(const char * song){
			cout<<"播放歌曲<<"<<song<<">>"<<endl;
		}
		MP3()
		{
			cout<<"MP3 constructor"<<endl;
		}

		~MP3()
		{
			cout<<"MP3 destructor"<<endl;
		}
};

class Phone{
	public:
		void dial(const char* no){
			cout<<"给"<<no<<"打电话"<<endl;
		}

		Phone()
		{
			cout<<"Phone constructor"<<endl;
		}
		Phone(const char *factory)
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

		ModernPhone(const char* factory):Phone(factory)
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
	ModernPhone mp("china");
	mp.dial("120");
	mp.take("trees");
	mp.play("i want it that way");
	mp.visitnet("www.google.com");

	return 0;
}
