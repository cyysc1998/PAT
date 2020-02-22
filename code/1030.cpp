#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class edge {
public:
    int n_id;
    int dis;
    int cost;
    edge(int n_id, int dis, int cost) : n_id(n_id), dis(dis), cost(cost){}
};

class node {
public:
    bool known;
    vector<edge> neigh;
    int mindis;
    int mincost;
    int pre;
    node(): known(false), mindis(INT_MAX), mincost(INT_MAX), pre(INT_MAX){}
};

int main(void) {
    int N, M, S, D;
    cin >> N >> M >> S >> D;
    vector<node> nodes(N);
    int t_s, t_d, t_dis, t_c;
    for(int i = 0; i < M; i++) {
        cin >> t_s >> t_d >> t_dis >> t_c;
        nodes[t_s].neigh.push_back(edge(t_d, t_dis, t_c));
        nodes[t_d].neigh.push_back(edge(t_s, t_dis, t_c));
    }

    nodes[S].known = true;
    nodes[S].mindis = 0;
    nodes[S].mincost = 0;
    nodes[S].pre = -1;

    for(auto e: nodes[S].neigh) {
        nodes[e.n_id].mindis = e.dis;
        nodes[e.n_id].mincost = e.cost;
        nodes[e.n_id].pre = S;
    }

    int k_n = 1;
    while(k_n < N) {
        int min = 0;
        while(nodes[min].known && min <N) min++;
        
        for(int i=min; i<N; i++) {
            if(!nodes[i].known && nodes[i].mindis < nodes[min].mindis)
                min = i;
        }
        
        node& minnode = nodes[min];
        minnode.known = true;
        
        for(auto& e: minnode.neigh) {
            if(nodes[e.n_id].mindis > minnode.mindis + e.dis) {
                nodes[e.n_id].mindis = minnode.mindis + e.dis;
                nodes[e.n_id].mincost = minnode.mincost + e.cost;
                nodes[e.n_id].pre = min;
            }
            else if(nodes[e.n_id].mindis == minnode.mindis + e.dis) {
                if(nodes[e.n_id].mincost >= minnode.mincost + e.cost) {
                    nodes[e.n_id].mincost = minnode.mincost + e.cost;
                    nodes[e.n_id].pre = min;
                }
            }
        }
        k_n++;
    }
    

    vector<int> ans;
    node temp = nodes[D];
    ans.push_back(D);
    while(temp.pre != -1) {
        ans.push_back(temp.pre);
        temp = nodes[temp.pre];
    }
    for(int i=ans.size()-1; i>=0; i--)
        cout << ans[i] << " ";
    cout << nodes[D].mindis << " " << nodes[D].mincost;
}