#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int> dis(N);
    for(int i = 0; i < N; i++)
        cin >> dis[i];
    int M;
    cin >> M;
    vector<int> st(M), des(M);
    for(int i = 0; i < M; i++) {
        cin >> st[i];
        cin >> des[i];
    }
    vector<int> s(N);

    int sum = 0;
    for(int i=0; i< N; i++) {
        if(i != 0)
            s[i] = s[i-1] + dis[i-1];
        sum += dis[i];
    }
        
    int n = st.size();
    for(int i=0; i<n; i++) {
        int dis = fabs(s[st[i]-1] - s[des[i]-1]);
        cout << min(dis, sum-dis) << endl;
    }
    return 0;
}