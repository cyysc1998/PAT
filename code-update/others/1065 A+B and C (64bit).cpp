#include <iostream>

using namespace std;

typedef long long int LL;

int n;

bool check(LL a, LL b, LL c) {
    if(a >= 0 && b >= 0 && a + b < 0) return true; 
    if(a < 0 && b < 0 && a + b > 0) return false;
    return a + b > c;
}

int main(void) {
    LL a, b, c;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a >> b >> c;
        if (check(a, b, c)) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
}