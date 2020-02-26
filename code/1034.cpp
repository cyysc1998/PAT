#include<bits/stdc++.h>
using namespace std;

map<int, string> i2s;
map<string, int> s2i;

class gang {
public:
    int r;
    vector<int> m;
    int time;
    int rp;
};

int totalID = 1;

int getID(string s) {
    if(s2i[s] == 0) 
        s2i[s] = totalID++;
    return s2i[s];
}

int Find(int i, vector<int>& k) {
    if(k[i] == -1)
        return i;
    return k[i] = Find(k[i], k);
}

void Union(int i, int j, vector<int>& k) {
    int r1 = Find(i, k);
    int r2 = Find(j, k);
    if(r1 != r2)
        k[r1] = r2;
}

int main(void) {
    int N, K;
    cin >> N >> K;
    string s1, s2;
    int t;
    map<int, int> times;
    map<int, vector<int>> conn;

    for(int i=0; i<N; i++) {
        cin >> s1 >> s2 >> t;
        int id1 = getID(s1);
        int id2 = getID(s2);
        times[id1] += t;
        times[id2] += t;
        i2s[id1] = s1;
        i2s[id2] = s2;
        conn[id1].push_back(id2);
    }
    vector<int> k(totalID, -1);
    for(auto e: conn)
        for(auto s: e.second)
            Union(e.first, s, k); 
    
    map<int, gang> res;
    for(int i=1; i<totalID; i++)
        if(k[i] == -1) {
            res[i].m.push_back(i);
            res[i].r = i;
            res[i].rp = i;
            res[i].time += times[i];
        }


    for(int i=0; i<totalID; i++) {
        int r = Find(i, k);
        if(r != i) {
            res[r].m.push_back(i);
            res[r].time += times[i];
            if(times[res[r].rp] < times[i])
                res[r].rp = i;
        }
    }

    map<string, int> ans;

    for(auto e: res) {
        if(e.second.m.size() > 2 && e.second.time > K*2) { 
            ans[i2s[e.second.rp]] = e.second.m.size();
        }
    }

    cout << ans.size() << endl;
    for(auto e: ans)
        cout << e.first << " " << e.second << endl;

    return 0;
}