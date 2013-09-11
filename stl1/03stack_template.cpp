#include<iostream>
using namespace std;
#include<string>
#include<typeinfo>
template <typename T=int,int max=20>

//typedef std::string T;

class Stack{
    T a[max];
    int cur;
    public:
        Stack():cur(0){}
        void push(const T &d)throw(const char *);
        const T& pop()throw(const char*);
        const T& top()const throw(const char *);
        bool empty()const{return cur == 0;}
        bool full()const{return cur == max;};
        void clear(){cur = 0;}
        int size()const{return cur;}
};

template <typename T, int max>
void Stack<T, max>::push(const T &d)throw(const char *){
    if(full()) throw "满";
    a[cur++] = d;
}

template <typename T, int max>
const T & Stack<T, max>::pop()throw(const char *){
    if(empty()) throw "空";
    //cur--;
    return a[--cur];
}

template <typename T, int max>
const T& Stack<T, max>::top()const throw(const char *){
    if(empty())  throw "空";
    return a[cur-1];
}

int main()
{
    Stack<string,10> s;//此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量此处的10不能用变量，只能是字面值，因为数组的大小在编译时就要确定，所以不能是变量
    Stack<int, 20> d;//模板的实例化
    cout << typeid(s).name() <<endl;
    cout << typeid(d).name() << endl;
    s.push("hello");
    s.push("world");
    while(!s.empty())
        cout << s.pop() << endl;

    d.push(4);
    d.push(3);
    d.push(2);
    d.push(1);
    while(!d.empty())
        cout << d.pop() << endl;
}
