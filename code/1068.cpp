#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>& v, vector<int>& p, int M, int u, int sum, int& find) {
    if(sum == M) {
        find = 1;
        return;
    }
    if(sum > M)
        return;


    if(!find) {
        for(int i=u; i<v.size(); i++) {
            p.push_back(v[i]);
            dfs(v, p, M, i+1, sum+v[i], find);
            if(find) return;
            p.pop_back();
        }
    }
    return;
}

int main(void) {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> v(N);
    int sum = 0;
    for(int i=0; i<N; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    if(sum < M) {
        printf("No Solution\n");
        return 0;
    }

    sort(v.begin(), v.end());
    
    int find = 0;
    vector<int> p;
    dfs(v, p, M, 0, 0, find);
    
    if(find) {
        printf("%d", p[0]);
        for(int i=1; i<p.size(); i++)
            printf(" %d", p[i]);
    }
    else
        printf("No Solution\n");
    return 0;
}