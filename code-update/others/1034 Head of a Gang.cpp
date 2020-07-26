#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010;
unordered_map<string, int> mp;
unordered_map<int, string> names;
int g[N][N], idx;
bool st[N];
int n, k;

int get(string s) {
    if (!mp.count(s)) {
        mp[s] = idx++;
        names[idx-1] = s;
    }
    return mp[s];
}

int dfs(int u, int& resp, int& sum, vector<int>& cnt) {
    int s = 0;
    for (int i = 0; i < idx; i ++)
        s += g[u][i];
    if (s > sum) {
        resp = u;
        sum = s;
    }
    cnt.push_back(u);
    st[u] = true;
    int t = s;
    for (int i = 0; i < idx; i ++) {
        if (!st[i] && g[u][i]) 
            t += dfs(i, resp, sum, cnt); 
    }
    return t;
}

int main(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        int v;
        string a, b;
        cin >> a >> b >> v;
        int x = get(a), y = get(b);
        g[x][y] += v;
        g[y][x] += v;
    }

    vector<pair<string, int>> res;
    for (int i = 0; i < idx; i ++) {
        if (!st[i]) {
            int resp = 0, sum = 0;
            vector<int> cnt;
            int t = dfs(i, resp, sum, cnt); 
            if (t > 2 * k && cnt.size() >= 3) 
                res.push_back({names[resp], cnt.size()});
        }
    }

    cout << res.size() << endl;
    sort(res.begin(), res.end());

    for (auto& e: res)
        cout << e.first << " " << e.second << endl;
    
    return 0;
}