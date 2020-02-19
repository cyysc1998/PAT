#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class edge {
public:
    int ID;
    int dis;
    edge(int id, int dis) : ID(id), dis(dis) {}
};

class node {
public:
    int ID;
    int bike;
    int dis;
    vector<edge> Edge;
    vector<int> last;
    bool known;
    node(int id, int bike): ID(id), bike(bike), known(false), dis(INT_MAX) {}
};

int C, N, S, M;
int last_send = INT_MAX, last_back = INT_MAX;

void dfs(vector<node>& Node, int u, vector<int>& res, vector<int>&path) {
    if (u == 0) {
        int send = 0, back = 0;
        for (int i=path.size()-2; i>=0; i--) {
            if (Node[path[i]].bike >= C/2) 
                back += (Node[path[i]].bike - C/2);
            else {
                if (back >= (C/2 - Node[path[i]].bike)) {
                    back -= C/2 - Node[path[i]].bike;
                }
                else {
                    send += C/2 - Node[path[i]].bike - back; 
                    back = 0;
                }
            } 
        }
    
        if (send < last_send || send == last_send && back < last_back) {
            res.assign(path.begin(), path.end());
            last_send = send;
            last_back = back;
        }
        return;
    }
    
    for (auto e: Node[u].last) {
        path.push_back(e);
        dfs(Node, e, res, path);
        path.pop_back();
    }
}

int main(void) {
    cin >> C >> N >> S >> M;
    vector<node> Node;
    Node.push_back(node(0, INT_MAX));
    int t_b;
    for (int i=1; i<=N; i++) {
        cin >> t_b;
        Node.push_back(node(i, t_b));
    }
    int t_s, t_d, t_dis;
    for (int i=0; i<M; i++) {
        cin >> t_s >> t_d >> t_dis;
        Node[t_s].Edge.push_back(edge(t_d, t_dis));
        Node[t_d].Edge.push_back(edge(t_s, t_dis));
    }
    Node[0].known = true;
    Node[0].dis = 0;
    Node[0].last.push_back(0);
    for (auto e: Node[0].Edge) {
        Node[e.ID].dis = e.dis;
        Node[e.ID].last.push_back(Node[0].ID);
    }

    int k_n = 1;
    while (k_n < N+1) {
        int s_in = 0;
        for (int i=0; i<=N; i++) 
            if(!Node[i].known) {
                s_in = i;
                break;
            }
        for (int i=0; i<=N; i++) {
            if (!Node[i].known && Node[i].dis < Node[s_in].dis)
                s_in = i;
        }
        node& minNode = Node[s_in];
        minNode.known = true;

        for (auto e: minNode.Edge) {
            if (Node[e.ID].dis > minNode.dis + e.dis) {
                Node[e.ID].dis = minNode.dis + e.dis;
                Node[e.ID].last.clear();
                Node[e.ID].last.push_back(minNode.ID);
            }
            else if (Node[e.ID].dis == minNode.dis + e.dis) {
                Node[e.ID].last.push_back(minNode.ID);
            }
        }
        k_n++;
    }

    vector<int> res, path;
    path.push_back(S);
    dfs(Node, S, res, path);
    cout << last_send << " " << res[res.size()-1];
    for(int i=res.size()-2; i>=0; i--) 
        cout << "->" << res[i];
    cout << " " << last_back << endl;
}
 