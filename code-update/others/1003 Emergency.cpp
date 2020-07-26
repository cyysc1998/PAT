#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int g[N][N], dist[N], secure[N], c[N], cnt[N];
bool st[N];
int n, m, s, d;

void dijkstra(void) {
    memset(dist, 0x3f, sizeof dist);
    secure[s] = c[s];
    dist[s] = 0;
    cnt[s] = 1;
    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 0; j < n; j ++)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        for (int j = 0; j < n; j ++) {
            if (dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                secure[j] = secure[t] + c[j];
                cnt[j] = cnt[t];
            }
            else if (dist[j] == dist[t] + g[t][j]) {
                secure[j] = max(secure[j], secure[t] + c[j]);
                cnt[j] += cnt[t];
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> s >> d;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < n; i ++)
        cin >> c[i];
    for (int i = 0; i < m; i ++) {
        int a, b, v;
        cin >> a >> b >> v;
        g[a][b] = g[b][a] = min(g[a][b], v);
    }
    dijkstra();
    cout << cnt[d] << " " << secure[d] << endl;

    return 0;
}