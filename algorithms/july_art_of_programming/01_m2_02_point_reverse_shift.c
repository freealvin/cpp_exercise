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

    while (1)
    {
        swap(s, p, p2);
	p++;
	if (p2<length-1)
	    p2++;
	else
	    break;
    }

    // 尾部处理，r为尾部需要移动的字符个数
    int r = m - length%m;
    while(r--)
    {
        int p3 = p;
	char temp = s[p];
	while (p3 < p2)
	{
	    s[p3] = s[p3+1];
	    p3++;
	}
	s[p2] = temp;
    }
   // July编程艺术第一章思路二方法二
   // https://github.com/julycoding/The-Art-Of-Programming-by-July/blob/master/ebook/zh/01.0.md 

}

int
main()
{
    char s[] = "abcdefghij";
    rotate(s, 3);
    printf("%s\n", s);
    return 0;
}

