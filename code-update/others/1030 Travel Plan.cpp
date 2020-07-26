#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 510;
int g[N][N], c[N][N], dist[N], cost[N], pre[N];
bool st[N];
int n, m, s, d;

void dijkstra(void) {
    memset(dist, 0x3f, sizeof dist);
    memset(cost, 0x3f, sizeof cost);
    pre[s] = -1;
    cost[s] = 0;
    dist[s] = 0;
    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 0; j < n; j ++)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        for (int j = 0; j < n; j ++) {
            if (dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                cost[j] = cost[t] + c[t][j];
                pre[j] = t;
            }
            else if (dist[j] == dist[t] + g[t][j]) {
                if (cost[j] > cost[t] + c[t][j]) {
                    cost[j] = cost[t] + c[t][j];
                    pre[j] = t;
                }
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> s >> d;
    memset(g, 0x3f, sizeof g);
    memset(c, 0x3f, sizeof c);
    for (int i = 0; i < m; i ++) {
        int a, b, w, v;
        cin >> a >> b >> w >> v;
        g[a][b] = g[b][a] = min(g[a][b], w);
        c[a][b] = c[b][a] = min(c[a][b], v);
    }
    dijkstra();
    vector<int> res;
    for (int i = d; i != -1; i = pre[i])
        res.push_back(i);
    for (int i = res.size()-1; i >= 0; i --)
        cout << res[i] << " ";
    cout << dist[d] << " " << cost[d] << endl;

    return 0;
}
