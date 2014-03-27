#include <stdio.h>

void permutation(int array[], int begin, int end)
{
    int i;
    if(begin == end)
        printf("%d\n",array[begin]);
    for(i = begin; i < end; i++)
    {
        int temp = array[begin];
        array[begin] = array[i];
        array[i] = temp;
        printf("%d ", array[begin]);
        permutation(array, begin+1, end);
    } 
}

int main()
{
   int a[]  = {1, 2, 3};
   permutation(a, 0, 3);
}
