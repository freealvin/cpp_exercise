#include<iostream>

using namespace std;

template <int n>
class Fact{
public:
    enum{val = Fact<n-1>::val*n};
};

template <>
class Fact<0>{
    public:
        enum{val = 1};
};

int main()
{
    cout << Fact<5>::val << endl;
}
