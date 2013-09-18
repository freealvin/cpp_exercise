/*
 *2013年9月18日
 * 算法perm(list, k, m)递归地产生所有前缀是list[0:k-1]，且后缀是list[k:m]的全排列的所有排列。
 * 在一般情况下，k<m.算法将list[k:m]中每一个元素分别于list[k]元素交换，然后递归地计算list[k+1:m]的全排列，并将计算结果作为list[0:k]的后缀。
 * */
#include<iostream>

using namespace std;

template <typename T>
void swap(T object[], int i, int j)
{
    T temp = object[i];
    object[i] = object[j];
    object[j] = temp;
}

template <typename T>
void perm(T object[], int k, int m)
{
    if(k==m){
        for(int i=0;i<=m;i++)
	    cout << object[i] << ' ';
	cout << endl;
    }else{
        for(int i=k;i<=m;i++)
	{
	    swap(object, k, i);
	    perm(object, k+1, m);
	    swap(object, k, i);
	}
    }
}
int main()
{
    int object[4] = {1, 2, 3, 4};
    perm(object, 0, 3);

}

