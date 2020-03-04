#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int a1,b1, c1, a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    int c = (c1+c2)%29;
    int b = (b1+b2+(c1+c2)/29)%17;
    int a = a1+a2+(b1+b2+(c1+c2)/29)/17;
    printf("%d.%d.%d\n", a, b, c);
    return 0;
}