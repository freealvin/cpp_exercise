#include <stdio.h>
#include <string.h>
void
swap(char *s, int p1, int p2)
{
    char temp = s[p1];
    s[p1] = s[p2];
    s[p2] = temp;
}

void
rotate(char *s, int n, int m, int start, int end, int flag)
{
    if(start == end || m <= 0)
        return;
    
    //printf("start = %d, end = %d\n", start, end);
    //printf("n = %d\n", n);

    if (flag == 1)
    {
        int p1 = start;
	int p2 = start + m;

	int k = n - m - n % m;

	while (k--)
	{
	    swap(s, p1, p2);
	    p1++;
	    p2++;
	}

	rotate(s, m+n%m, n % m, p1, end, 0);
    }
    else
    {
        int p1 = end;
	int p2 = end - m;

	int k = n - m - n % m;

	while(k--)
	{
	    swap(s, p1, p2);
	    p1--;
	    p2--;
	}

	rotate(s, m+n%m, n % m, start, p1, 1);
    }
}

int
main()
{
    char s[] = "abcdefghij";

    rotate(s, strlen(s), 3, 0, strlen(s)-1, 1);

    printf("%s\n", s);

    return 0;
}
