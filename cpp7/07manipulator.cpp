#include<iostream>

using namespace std;

class wf{
    int w;
    char f;
    public:
        wf(int w, char f):w(w), f(f){}
        friend ostream & operator <<(ostream &o, const wf &t){
            o.width(t.w);
            o.fill(t.f);
            return o;
        }
};

int main()
{

    cout << wf(10, '*') << "good" << endl;
    return 0;

}
