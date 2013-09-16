#include<iostream>

using namespace std;
//template <typename T>
typedef int T;
struct Node{
    T data;
    Node * next;
    Node (const T & d):data(d), next(NULL){}
    operator T(){return data;}//类型转换运算符,tostring()
};

void showlist(Node *head)
{
    Node *p = head;
    while(p!=NULL){
        cout << *p << ' ';
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Node a(10), b(20), c(30), d(40), e(50), f(60);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    showlist(&a);
    Node * &q = a.next;//为a.next起个别名

    //一下两个语句把f插到a之后
    f.next = q;//把q赋给f的next
    q = &f;//把f赋给q,即a.next
    showlist(&a);
    cout << a << endl;//如果有未知类型，编译器会尝试自动调用一次类型转换
}
