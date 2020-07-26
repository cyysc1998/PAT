#include <iostream>
#include <unordered_map>

using namespace std;

const int M = 810, N = 610;
unordered_map<int, int> mp;
int m, n;

int main(void) {
    cin >> m >> n;
    for (int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            int v;
            cin >> v;
            mp[v]++;
        }
    }
    int res = 0, cnt = -1;
    for(auto& p: mp) {
        if(cnt < p.second) {
            cnt = p.second;
            res = p.first;
        }
    }
    cout << res << endl;

    return 0;
}