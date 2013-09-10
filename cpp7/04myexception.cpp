#include<iostream>
#include<exception>
#include<cstdio>

using namespace std;

class MyException : public exception{
    public:
        const char * what(){
            return "myexception";
        }
};

void f()throw(const char*, double, int, MyException)
{
    cout << "请输入一个整数(1-4):";
    int n;
    cin >> n;
    if(n==1) throw "const char *";
    if(n==2) throw 4.5;
    if(n==3) throw 3;
    if(n==4) throw MyException();

    cout << "function f() end" << endl;
}

class ME : public exception{
    char msg[100];
    public:
        ME(int line){
            sprintf(msg, "从第%d行抛出异常", line);
            cout << "msg:" << msg <<endl;
        }

        const char* what()const throw(){
            return msg;
        }
};

void g(){

    try{
    f();
    }
    catch(const char * ex){
        cout << "exception:" << ex << endl;
    }
    catch(int ex){
        cout << "exception:" << ex << endl;
    }
    catch(MyException ex){
        cout << "exception:" << ex.what() << endl;
    }
    catch(...){
        cout << "g:default" << endl;
        throw ME(__LINE__);
    }
}

int main()
{
    try{
        g();
    }
    catch(exception &e){
        cout << "main:" << e.what() << endl;
    }
    catch(...){
        cout << "default error" << endl;
    }
    return 0;

}
