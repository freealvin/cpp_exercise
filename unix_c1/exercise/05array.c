#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10000

int a[N];
int count[N];
void gen_random(int upper_bound)
{
    int i;
    srand(time(0));
    //要先设置种子，编译器里如果不设置种子，种子会默认为0，那么每次运行的随即数都一样的。用time函数来改变种子，就可以很好的体现出“真正的随即”了。 
    for(i=0; i<N; i += 1)
      a[i] = rand()%upper_bound;
}

void howmany(int n)
{
    int i;
    for(i=0;i<n;i++)
        count[i] = 0;

    for(i=0;i<N;i++)
    {
        count[a[i]] += 1;
    }
}

void print_random()
{
    int i;
    for(i=0; i<N; i += 1)
      printf("%d ", a[i]);
    printf("\n");

}

void print_graphic()
{
    int i;
}

int main()
{
    int n = 10;
    gen_random(n);
    //print_random();
    howmany(n);
    int i;
    for(i=0; i<n; i++)
        printf("%d : %d\n", i, count[i]);
    return 0;
}
