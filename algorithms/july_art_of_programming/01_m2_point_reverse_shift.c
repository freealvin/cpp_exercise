#include <stdio.h>
#include <string.h>

void
swap(char *s, int p, int p2)
{
    char c = s[p];
    s[p] = s[p2];
    s[p2] = c;
}

void
rotate(char *s, int m)
{
    int length = strlen(s);

    if (length==0 || m <= 0)
        return;
    if (m % length <= 0)
        return;

    int p = 0;
    int p2 = m;

    int k = (length - m) - length % m;

    while (k--)
    {
        swap(s, p, p2);
	p++;
	p2++;
    }

    // 尾部处理，r为尾部需要移动的字符个数
    int r = length - p2;
    while(r--)
    {
        int p3 = p2;
	while(p3>p)
	{
	    swap(s, p3, p3-1);
	    p3--;
	}
	p++;
	p2++;
    }
}

int
main()
{
    char s[] = "abcdefghij";
    rotate(s, 3);
    printf("%s\n", s);
    return 0;
}

