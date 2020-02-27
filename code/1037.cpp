#include<bits/stdc++.h>
using namespace std;

// dfs, tle

// void f(int u, int sum, vector<int>& a, vector<int>& b, vector<bool>& st, int& res) {
//     int n = a.size();
//     if(u == n && sum > res) {
//         res = sum;
//         return;
//     }
//     for(int i=0; i<n; i++) {
//         if(!st[i]) {
//             st[i] = true;
//             f(u+1, sum+a[u]*b[i], a, b, st, res);
//             st[i] = false;
//         }
//     }
// }

int main(void) {
    vector<int> a1, a2, b1, b2;
    ios::sync_with_stdio(false);
    int M, N;
    cin >> M;
    int temp;
    for(int i = 0; i < M; i++) {
        cin >> temp;
        if(temp > 0)
            a1.push_back(temp);
        else
            a2.push_back(-temp);
    }
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> temp;
        if(temp > 0)
            b1.push_back(temp);
        else
            b2.push_back(-temp);
    }

    sort(a1.rbegin(), a1.rend());
    sort(a2.rbegin(), a2.rend());
    sort(b1.rbegin(), b1.rend());
    sort(b2.rbegin(), b2.rend());

    int la = min(a1.size(), b1.size());
    int lb = min(a2.size(), b2.size());

    a1.assign(a1.begin(), a1.begin()+la);
    b1.assign(b1.begin(), b1.begin()+la);
    a2.assign(a2.begin(), a2.begin()+lb);
    b2.assign(b2.begin(), b2.begin()+lb);

    int sum = 0;

    for(int i=0; i<a1.size(); i++)
        sum += a1[i]*b1[i];

    for(int i=0; i<a2.size(); i++)
        sum += a2[i]*b2[i];

    cout << sum << endl;
    
    return 0;
}