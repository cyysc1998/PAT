#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios:: sync_with_stdio(false);
    map<string, vector<int>> p;
    int N, K;
    cin >> N >> K;
    int c, n;
    string stu;
    for(int i = 0; i < K; i++) {
        cin >> c >> n;
        for(int j=0; j<n; j++) {
            cin >> stu;
            p[stu].push_back(c);
        }
    }

    for(int i=0; i<N; i++) {
        cin >> stu;
        cout << stu << " " << p[stu].size();
        sort(p[stu].begin(), p[stu].end());
        for(auto e: p[stu])
            cout << " " << e;
        cout << endl;
    }
    return 0;
}