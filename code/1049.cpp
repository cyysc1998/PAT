#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    int res = 0;
    for (int i = 1; i <= N; i *= 10) {
        res += N / (i * 10) * i;
        int x = (N / i) % 10;
        res += x > 1 ? i : (N % i + 1) * x;
    }
    cout << res << endl;
    return 0;
}