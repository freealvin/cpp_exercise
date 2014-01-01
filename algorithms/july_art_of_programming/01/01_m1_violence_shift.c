#include <stdio.h>
#include <string.h>

void
leftshiftone(char *s, int n) {
    char t = s[0];
    int i;
    for (i = 1; i < n; i++) {
        s[i-1] = s[i];
    }
    s[n-1] = t;
}

void
leftshift(char *s, int n, int m) {
    while (m--) {
        leftshiftone(s, n);
    }
}

int
main() {
    
    // 这里s不能是字符指针，否则出现段错误
    char s[] = "abcdefghijk";
    int n = strlen(s);
    //printf("%d\n", n);
    leftshift(s, n, 3);
    printf("%s\n", s);
    return 0;
}
