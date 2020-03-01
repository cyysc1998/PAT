#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int weight;
    vector<int> child;
};


vector<vector<int>> res;

void dfs(vector<node>& T, int S, int sum, int u, vector<int>& sk) {
    if(T[u].child.empty()) {
        if(sum == S) 
            res.push_back(sk);
        return;
    }

    for(int i=T[u].child.size()-1; i>=0; i--) {
        sk.push_back(T[T[u].child[i]].weight);
        dfs(T, S, sum + T[T[u].child[i]].weight, T[u].child[i], sk);
        sk.pop_back();
    }
}

int main(void) {
    int N, M, S;
    cin >> N >> M >> S;
    vector<node> T(N);
    for(int i=0; i<N; i++)
        cin >> T[i].weight;
    for(int i=0; i<M; i++) {
        int t, k, id;
        cin >> t >> k;
        for(int j=0; j<k; j++) {
            cin >> id;
            T[t].child.push_back(id);
        }
    }
    vector<int> sk;
    dfs(T, S, T[0].weight, 0, sk);

    sort(res.rbegin(), res.rend());
    for(int i=0; i<res.size(); i++) {
        cout << T[0].weight;
        for(auto e: res[i])
            cout << " " << e;
        cout << endl;
    }
    return 0;
}