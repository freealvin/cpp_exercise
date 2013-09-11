#include<iostream>
#include<algorithm>
using namespace std;
using std::swap;

template <typename T>
void sort(T *a, int n)
{
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min = j;
        }
        swap(a[min], a[i]);
    }
}

int main()
{
    int a[5] = {6, 1, 9, 2, 8};
    double b[4] = {3.3, 5.5, 2.3, 1.0};
    sort(a, 5);
    sort(b, 4);
    for(int i=0;i<5;i++)
        cout << a[i] << ' ' ;

    cout<< endl;

    for(int i=0;i<4;i++)
        cout << showpoint  << b[i] << ' ';
    cout << endl;
}
