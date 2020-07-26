#include <iostream>

using namespace std;

const int N = 510;
int g[N][N], degree[N];
bool st[N];
int n, m;

void dfs(int u) {
    st[u] = true;
    for (int i = 1; i <= n; i ++) {
        if (g[u][i] && !st[i])
            dfs(i);
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
        degree[a]++;
        degree[b]++;
    }

    bool is_connected = true;
    dfs(1);

    int odd = 0, even = 0;
    for (int i = 1; i <= n; i ++) {
        if (degree[i] % 2 == 0) even++;
        else odd++;
        if (!st[i])
            is_connected = false;
    }
    cout << degree[1];
    for (int i = 2; i <= n; i ++)
        cout << " " << degree[i];
    cout << endl;

    if (odd == 0 && is_connected) puts("Eulerian");
    else if (odd == 2 && is_connected) puts("Semi-Eulerian");
    else puts("Non-Eulerian");

    return 0;
}