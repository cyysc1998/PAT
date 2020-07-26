#include <iostream>
#include <cstring>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 210;
unordered_map<string, int> mp;
unordered_map<int, string> names;
int c[N][N], h[N], idx;
int cost[N], happiness[N], cnt[N], dist[N], pre[N];
bool st[N];
int n, k, s, d;
string start;

int get(string s) {
    if (!mp.count(s)) {
        mp[s] = idx++;
        names[idx-1] = s;
    }
    return mp[s];
}

void dijkstra(void) {
    memset(cost, 0x3f, sizeof cost);
    memset(dist, 0x3f, sizeof dist);
    cost[s] = 0;
    happiness[s] = h[s];
    dist[s] = 0;
    cnt[s] = 1;
    pre[s] = -1;

    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 0; j < n; j ++) 
            if (!st[j] && (t == -1 || cost[j] < cost[t]))
                t = j;
        st[t] = true;
        
        for (int j = 0; j < n; j ++) {
            if (cost[j] > cost[t] + c[t][j]) {
                cost[j] = cost[t] + c[t][j];
                happiness[j] = happiness[t] + h[j];
                cnt[j] = cnt[t];
                dist[j] = dist[t] + 1;
                pre[j] = t;
            }
            else if (cost[j] == cost[t] + c[t][j]) {
                if (happiness[j] < happiness[t] + h[j]) {
                    happiness[j] = happiness[t] + h[j];
                    dist[j] = dist[t] + 1;
                    pre[j] = t;
                }
                else if (happiness[j] == happiness[t] + h[j]) {
                    if (dist[j] > dist[t] + 1) {
                        dist[j] = dist[t] + 1;
                        pre[j] = t;
                    }
                }
                cnt[j] += cnt[t];
            }
        }
    }
}

int main(void) {
    cin >> n >> k >> start;
    s = get(start);
    d = get("ROM");
    memset(c, 0x3f, sizeof c);
    for (int i = 0; i < n - 1; i ++) {
        string t;
        int v;
        cin >> t >> v;
        h[get(t)] = v;
    }
    for (int i = 0; i < k; i ++) {
        string a, b;
        int v;
        cin >> a >> b >> v;
        int x = get(a), y = get(b);
        c[x][y] = c[y][x] = min(c[x][y], v);
    }
    dijkstra();
    cout << cnt[d] << " " << cost[d] << " " << happiness[d] << " " << happiness[d] / dist[d] << endl;
    vector<string> res;
    for (int i = d; i != -1; i = pre[i])
        res.push_back(names[i]);
    cout << res.back();
    for (int i = res.size() - 2; i >= 0; i--) 
        cout << "->" << res[i];
    cout << endl;
  
    return 0;
}
