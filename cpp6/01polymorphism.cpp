#include<iostream>
using namespace  std;

class Animal{
    public:
        void play(){
            eat();
            shout();
            sleep();
        }

        Animal(){
            sleep();
        }

        virtual ~Animal()
        {
            cout<<"Animal dead"<<endl;
        }
       virtual void eat(){cout<<"吃"<<endl;}
        virtual void shout(){cout<<"叫"<<endl;}
        virtual void sleep(){cout<<"睡"<<endl;}
};

class Horse : public Animal{
    public:
        virtual void eat(){cout<<"马吃草"<<endl;}
        virtual void shout(){cout<<"马嘶鸣"<<endl;}
        virtual void sleep(){cout<<"马卧着睡"<<endl;}
};

class Tiger : public Animal{
    public:
        virtual void eat(){cout<<"虎吃肉"<<endl;}
        virtual void shout(){cout<<"虎啸"<<endl;}
        virtual void sleep(){cout<<"虎睡觉"<<endl;}
        virtual ~Tiger(){
            cout<<"Tiger Dead"<<endl;
        }
};

int main()
{
    Animal *p = NULL;
    char t;
    cin >> t;
    if(t=='t')
        p = new Tiger;
    else
        p = new Horse;
    p->play();
    delete p;
    return 0;
}
