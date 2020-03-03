#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios:: sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    map<int, int> p;
    int t;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> t;
            p[t]++;
        }
    }
    int res = -1, max_val = INT_MIN;
    for(auto e: p) {
        if(e.second > max_val) {
            max_val = e.second;
            res = e.first;
        }
    }
    cout << res << endl;
    return 0;
}