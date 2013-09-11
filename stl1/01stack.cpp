#include<iostream>
using namespace std;
#include<string>

typedef std::string T;

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

void Stack::push(const T &d)throw(const char *){
    if(full()) throw "满";
    a[cur++] = d;
}

const T & Stack::pop()throw(const char *){
    if(empty()) throw "空";
    //cur--;
    return a[--cur];
}

const T& Stack::top()const throw(const char *){
    if(empty())  throw "空";
    return a[cur-1];
}

int main()
{
    Stack s;
    s.push("hello");
    s.push("world");
    while(!s.empty())
        cout << s.pop() << endl;
}
