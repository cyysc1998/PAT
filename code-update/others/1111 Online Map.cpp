#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 510, M = N * (N - 1) / 2;
int g[N][N], cost[N][N];
int dist[N], times[N], cnt[N], pre[N];
bool st[N];
int n, m, s, d;

void dijkstra1(void) {
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    memset(times, 0x3f, sizeof times);
    dist[s] = 0;
    times[s] = 0;
    pre[s] = -1;

    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 0; j < n; j ++)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;

        for (int j = 0; j < n; j ++) {
            if (dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                times[j] = times[t] + cost[t][j];
                pre[j] = t;
            }
            else if (dist[j] == dist[t] + g[t][j]) {
                if (times[j] > times[t] + cost[t][j]) {
                    times[j] = times[t] + cost[t][j];
                    pre[j] = t;
                }
            }
        }
    }
}

void dijkstra2(void) {
    memset(st, 0, sizeof st);
    memset(times, 0x3f, sizeof times);
    memset(pre, 0, sizeof pre);
    times[s] = 0;
    cnt[s] = 0;
    pre[s] = -1;

    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 0; j < n; j ++) 
            if (!st[j] && (t == -1 || times[j] < times[t]))
                t = j;
        st[t] = true;

        for (int j = 0; j < n; j ++) {
            if (times[j] > times[t] + cost[t][j]) {
                times[j] = times[t] + cost[t][j];
                cnt[j] = cnt[t] + 1;
                pre[j] = t;
            }
            else if (times[j] == times[t] + cost[t][j]) {
                if (cnt[j] > cnt[t] + 1) {
                    cnt[j] = cnt[t] + 1;
                    pre[j] = t;
                }
            }
        }
    }
}

int main(void) {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    memset(cost, 0x3f, sizeof cost);

    for (int i = 0; i < m; i ++) {
        int a, b, type, length, T;
        cin >> a >> b >> type >> length >> T;
        if (type == 0) {
            g[a][b] = g[b][a] = min(g[a][b], length);
            cost[a][b] = cost[b][a] = min(cost[a][b], T);
        }
        else {
            g[a][b] = min(g[a][b], length);
            cost[a][b] = min(cost[a][b], T);
        }
    }
    cin >> s >> d;
    dijkstra1();
    int distance1 = dist[d], time1 = times[d];
    vector<int> path1;
    for (int i = d; i != -1; i = pre[i])
        path1.push_back(i);
    
    dijkstra2();
    int distance2 = dist[d], time2 = times[d];
    vector<int> path2;
    for (int i = d; i != -1; i = pre[i])
        path2.push_back(i);
    
    if (path1 == path2) {
        printf("Distance = %d; Time = %d: ", distance1, time1);
        cout << s;
        for (int i = path1.size() - 2; i >= 0; i--)
            printf(" -> %d", path1[i]);
        cout << endl;
    }
    else {
        printf("Distance = %d: ", distance1);
        cout << s;
        for (int i = path1.size() - 2; i >= 0; i--)
            printf(" -> %d", path1[i]);
        cout << endl;
        printf("Time = %d: ", time2);
        cout << s;
        for (int i = path2.size() - 2; i >= 0; i--)
            printf(" -> %d", path2[i]);
        cout << endl;
    }
    return 0;
}