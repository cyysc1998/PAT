#include<iostream>
#include<vector>
using namespace std;

class node {
public:
    int id;
    bool st;
    vector<int> neigh;
    node(int id): id(id), st(false) { }
};

vector<int> res;
int m_len = 0;

int bfs(vector<node>& g, int s) {
    int len = 0;
    vector<int> now, next;
    now.push_back(s);
    g[s].st = true;
    while(!now.empty()) {
        for(auto k: now) {
            for(auto& n : g[k].neigh) {
                if(!g[n].st) {
                    next.push_back(g[n].id);
                    g[g[n].id].st = true;
                }
            }
        }
        len++;
        now = next;
        next.clear();
    }

    if(len > m_len) {
        res.clear();
        res.push_back(s);
        m_len = len;
    }
    else if(len == m_len) {
        res.push_back(s);
    }
    
    for(int i=1; i<g.size(); i++) {
        if(!g[i].st) 
            return 1;
    }

    return 0;

}

int main(void) {
    int N;
    cin >> N;
    vector<node> g;
    for(int i=0; i<=N; i++) {
        g.push_back(node(i));
    }
    
    int t_s, t_d;
    for(int i = 0; i < N-1; i++) {
        cin >> t_s >> t_d;
        g[t_s].neigh.push_back(t_d);
        g[t_d].neigh.push_back(t_s);
    }
    
    int ans = 0;
    for(int i=1; i<g.size(); i++) {
        if(!g[i].st) {
            
            ans += bfs(g, i);
        }
    }

    if(ans == 0) { 
        for(int i=2; i<g.size(); i++) {
            for(int j=1; j<g.size(); j++) g[j].st = false;
            bfs(g, i);
        }
        for(auto r: res)
            cout << r << endl;
    }
    else
        cout << "Error: " << ans+1 << " components" << endl;
}

