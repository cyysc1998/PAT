#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {
    double res = 1;
    for(int i = 0; i < 3; i ++) {
        double a, b, c;
        unordered_map<double, char> mp;
        cin >> a >> b >> c;
        mp[a] = 'W', mp[b] = 'T', mp[c] = 'L';
        double m = max(a, max(b, c));
        res *= m;
        cout << mp[m] << " ";
    }
    printf("%.2lf\n", (res * 0.65 - 1) * 2);
    return 0;
}