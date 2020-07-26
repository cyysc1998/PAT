#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

const int N = 310;
unordered_map<int, bool> gender;
unordered_map<int, unordered_set<int>> relations;
int n, m, k;

int getId(string s) {
    int t;
    if (s[0] == '-') {
        s = s.substr(1);
        t = stoi(s);
        gender[t] = 0;
    }
    else {
        t = stoi(s);
        gender[t] = 1;
    }
    return t;
}

int main(void) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i ++) {
        char a[10], b[10];
        scanf("%s%s", a, b);
        int x = getId(a), y = getId(b);
        relations[x].insert(y);
        relations[y].insert(x);
    }
    scanf("%d", &k);
    while (k --) {
        char a[10], b[10];
        scanf("%s%s", a, b);
        int x = getId(a), y = getId(b);
        vector<pair<int, int>> res;
        auto& xfriends = relations[x], yfriends = relations[y];
        for (auto& xfriend : xfriends) {
            for (auto& yfriend : yfriends) {
                if (xfriend != y && yfriend != x) {
                    if (gender[x] == gender[xfriend] && gender[y] == gender[yfriend]) {
                        if (relations[xfriend].count(yfriend) || relations[yfriend].count(xfriend))
                            res.push_back({xfriend, yfriend});
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        cout << res.size() << endl;
        for (auto& e: res)
            printf("%04d %04d\n", e.first, e.second);
    }
    return 0;
}
