#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    map<int, int> p;
    vector<int> g;

    int k;
    for(int i = 0; i < N; i++) {
        cin >> k;
        g.push_back(k);
        p[k]++;
    }

    bool flag = false;
    for(auto e: g) {
        if(p[e] == 1) {
            cout << e << endl;
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << "None" << endl;
    return 0;
}