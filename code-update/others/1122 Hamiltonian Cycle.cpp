#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 210;
bool g[N][N], st[N];
int n, m, k;

bool judge(vector<int>& path) {
    if (path.size() != n + 1 || path.front() != path.back()) return false;
    memset(st, 0, sizeof st);

    for (int i = 0; i < path.size() - 1; i++) {
        int e = path[i], t = path[i + 1];
        if (st[e] || !g[e][t]) return false;
        else st[e] = true;
    }
    
    for (int i = 1; i <= n; i ++) 
        if (!st[i])
            return false;
    return true;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }
    cin >> k;
    while (k --) {
        vector<int> path;
        int t, v;
        cin >> t;
        for (int i = 0; i < t; i ++) {
            cin >> v;
            path.push_back(v);
        }
        if (judge(path)) puts("YES");
        else puts("NO");
    }
    return 0;
}