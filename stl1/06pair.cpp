#include<iostream>
using namespace std;

template <typename T, typename U>
struct Pair{
    T first;
    U second;
    Pair():first(),second(){}
    Pair(const T &a, const U &b):first(a),second(b){}
};

template <typename T, typename U>
ostream &operator <<(ostream &o, const Pair<T, U> &p)
{
    return o << p.first << ':' << p.second;
}

template <typename T, typename U>
Pair<T, U> mp(T t, U u)
{
    Pair<T,U> obj(t, u);
    return obj;
}
int main()
{
    cout << Pair<const char *, int>("Alvin", 21) << endl;
    cout << Pair<int , double>(20, 678.5) <<endl;
    cout << mp("Alvin", 21) << endl;
    cout << mp(20, 678.5) <<endl;
}
