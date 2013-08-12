#include<iostream>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

int get(int &t)
{
	return t;
}


int main()
{
	get(add(1,2));
	return 0;
}
