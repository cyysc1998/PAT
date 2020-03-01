#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    map<int, int> s, p;
    int t;
    for(int i=0; i<N; i++) {
        cin >> t;
        s[t] += 1;
    }
    p = s;
    for(auto e: s) {
        if(p[M-e.first] != 0) {
            if(!(e.first == M-e.first && p[M-e.first] == 1)) {
                cout << e.first << " " << M-e.first << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;

    return 0;
}