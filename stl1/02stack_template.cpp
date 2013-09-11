#include<iostream>
using namespace std;
#include<string>
#include<typeinfo>
template <typename T>

//typedef std::string T;

class Stack{
    T a[5];
    int cur;
    public:
        Stack():cur(0){}
        void push(const T &d)throw(const char *);
        const T& pop()throw(const char*);
        const T& top()const throw(const char *);
        bool empty()const{return cur == 0;}
        bool full()const{return cur == 5;};
        void clear(){cur = 0;}
        int size()const{return cur;}
};

template <typename T>
void Stack<T>::push(const T &d)throw(const char *){
    if(full()) throw "满";
    a[cur++] = d;
}

template <typename T>
const T & Stack<T>::pop()throw(const char *){
    if(empty()) throw "空";
    //cur--;
    return a[--cur];
}

template <typename T>
const T& Stack<T>::top()const throw(const char *){
    if(empty())  throw "空";
    return a[cur-1];
}

int main()
{
    Stack<string> s;//模板的实例化：把模板的未定类型确定下来
    Stack<int > d;//模板的实例化
    cout << typeid(s).name() <<endl;
    cout << typeid(d).name() << endl;
    s.push("hello");
    s.push("world");
    while(!s.empty())
        cout << s.pop() << endl;
}
