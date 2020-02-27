#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    getline(cin, s);
    int n = s.size();
    vector<vector<bool>> r(n, vector<bool>(n));

    int len = 0;
    for(int j=0; j<n; j++) {
        for(int i=j; i>=0; i--) {
            if(s[i]==s[j] && (j-i<3 || r[i+1][j-1])) {
                r[i][j] = true;
                if(r[i][j] && j-i+1>len)
                    len = j-i+1;
            }
        }
    }
    return 0;
}