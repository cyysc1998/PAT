#include<bits/stdc++.h>
using namespace std;

int sort_n(int n) {
    vector<int> p(4);
    p[0] = n%10;
    p[1] = (n/10)%10;
    p[2] = (n/100)%10;
    p[3] = (n/1000);
    sort(p.rbegin(), p.rend());
    return p[3] + 10*p[2] + 100*p[1] + 1000*p[0];
}

int reverse(int n) {
    vector<int> p(4);
    p[0] = n%10;
    p[1] = (n/10)%10;
    p[2] = (n/100)%10;
    p[3] = (n/1000);
    return p[3] + 10*p[2] + 100*p[1] + 1000*p[0];
}

int main(void) {
    int N;
    cin >> N;
    while(true) {
        N = sort_n(N);
        int re = reverse(N);
        int diff = N - re;
        printf("%04d - %04d = %04d\n", N, re, diff);
        N = diff;
        if(N == 0 || N == 6174)
            break;
    }
    return 0;
}