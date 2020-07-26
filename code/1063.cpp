#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N, M, K;
    scanf("%d", &N);
    vector<set<int>> p(N+1);
    for(int i=1; i<=N; i++) {
        scanf("%d", &M);
        int t;
        for(int j=0; j<M; j++) {
            scanf("%d", &t);
            p[i].insert(t);
        }
    }
    scanf("%d", &K);
    int st, en;
    for(int i=0; i<K; i++) {
        scanf("%d%d", &st, &en);
        int Nc = 0, Nt = 0;

        for(auto& e: p[st]) {
            if(p[en].find(e) != p[en].end())
                Nc++;
        }
        Nt = p[st].size() + p[en].size() - Nc;
        printf("%.1lf%\n", 100.0*Nc/Nt);
    }
    return 0;
}