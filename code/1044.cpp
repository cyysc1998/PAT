#include<bits/stdc++.h>
using namespace std;

int find(int p, int q, int M, vector<int>& sn, vector<int>& d) {
    int left = p + 1;
    int right = q;
    while(left < right) {
        int mid = left + (right-left)/2;
        if(sn[mid] - sn[p] >= M)
            right = mid;
        else 
            left = mid + 1;
    }
    d[p] = right;
    return sn[right] - sn[p];
}

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> sn(N+1), d(N+1), res;

    for(int i=1; i<=N; i++) {
        cin >> sn[i];
        sn[i] = sn[i-1] + sn[i];
    }

    int lmax = INT_MAX;

    for(int i=0; i<N; i++) {
        int tmp = find(i, N, M, sn, d);
        if(tmp >= M) {
            if(tmp == lmax) 
                res.push_back(i);
            else if(tmp < lmax) {
                lmax = tmp;
                res.clear();
                res.push_back(i);
            }
        }
        else
            break;
    }
    for(auto e: res) 
        cout << e + 1 << "-" << d[e] << endl;

    return 0;

}