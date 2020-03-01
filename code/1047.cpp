#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N, K;
    scanf("%d%d", &N, &K);
    vector<vector<string>> s(K+1);
    string name;
    int C, t;
    for(int i=0; i<N; i++) {
        cin >> name >> C;
        for(int j=0; j<C; j++) {
            scanf("%d", &t);
            s[t].push_back(name);
        }
    }
    for(int i=1; i<s.size(); i++) {
        sort(s[i].begin(), s[i].end());
        printf("%d %d\n", i, s[i].size());
        for(int j=0; j<s[i].size(); j++) 
            printf("%s\n", s[i][j].c_str());
    }
    return 0;
}