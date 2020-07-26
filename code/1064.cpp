#include<bits/stdc++.h>
using namespace std;

void dfs(int t, vector<int>& pos, int& count, int N) {
    if(t <= N) {
        dfs(2*t, pos, count, N);
        pos[t] = ++count;
        dfs(2*t+1, pos, count, N);
    }
}

int main(void) {
    int N;
    cin >> N;
    vector<int> val(N+1), pos(N+1);
    int count = 0;
    for(int i=1; i<=N; i++) 
        cin >> val[i];
    val[0] = INT_MIN;
    sort(val.begin(), val.end());
    dfs(1, pos, count, N);
    cout << val[pos[1]];
    for(int i=2; i<=N; i++)
        cout << " " << val[pos[i]];
    return 0;
}