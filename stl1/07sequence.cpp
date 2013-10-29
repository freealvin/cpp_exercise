#include <deque>
#include <iostream>
#include <string>

using  namespace std;

template <typename T>
void print(T a, T b, char c=' ')
{
    while( a != b )
        cout << *a++ << endl;
}

int main()
{
    deque<string> ds;
    ds.push_back("Hello");
    ds.push_back("Baidu");
    ds.push_back("Sina");
    ds.push_back("World");

    print(ds.begin(), ds.end());
    cout << ds.back() << endl;
    cout << ds.front() << endl;
    return 0;
}
