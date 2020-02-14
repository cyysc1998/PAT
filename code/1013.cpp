#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int find(int* us, int root){
    if(us[root]==root)
        return root;
    return us[root] = find(us, us[root]);
}

void join(int* us, int root_a, int root_b){
    int m = find(us, root_a);
    int n = find(us, root_b);
    us[m] = n;
}


int main(void){
    int N, M, K, t_s, t_d, t_c;
    vector<int> s, d;
    scanf("%d%d%d", &N, &M, &K);
    // cin >> N >> M >> K;
    int us[N+1];
    for(int i=0; i<M; i++){
        // cin >> t_s >> t_d;
        scanf("%d%d",&t_s,&t_d);
        s.push_back(t_s);
        d.push_back(t_d);
    }

    
    for(int i=0; i<K; i++){
        // cin >> t_c;
        scanf("%d",&t_c);
        for(int j=1; j<=N; j++)
            us[j] = j;
        for(int j=0; j<M; j++){
            if(s.at(j)!=t_c && d.at(j)!=t_c)
                join(us, s.at(j),d.at(j));
        }
        int ans = 0;
        for(int j=1; j<=N; j++){
            if(us[j]==j && j!=t_c)
                ans++;
        }
        cout << ans-1 << endl;
    }

}