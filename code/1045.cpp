#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N, M, L, t;
    cin >> N >> M;
    vector<int> sx(N+1);
    for(int i = 1; i <= M; i++) 
        cin >> sx[i];
    cin >> L;
    vector<int> sy(L+1);
    for(int i = 1; i <= L; i++)
        cin >> sy[i];

    vector<vector<int>> dp(M+1, vector<int>(L+1));
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=L; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i][j-1]);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(sx[i] == sy[j])
                dp[i][j]++;
        }
    }
    
    cout << dp[M][L] << endl;
    return 0;
}