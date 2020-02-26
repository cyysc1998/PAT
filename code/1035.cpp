#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<string> n(N), p(N);
    vector<int> ans;
    string s1, s2;
    for(int i=0; i<N; i++) {
        cin >> s1 >> s2;
        n[i] = s1;
        p[i] = s2;
    }
    for(int i=0; i<N; i++) {
        string& s = p[i];
        bool flag = false;
        for(int j=0; j<s.size(); j++) {
            if(s[j] == '1') {
                s[j] = '@';
                flag = true;
            }
            else if(s[j] == '0') {
                s[j] = '%';
                flag = true;
            }
            else if(s[j] == 'l') {
                s[j] = 'L';
                flag = true;
            }
            else if(s[j] == 'O') {
                s[j] = 'o';
                flag = true;
            }
        }
        if(flag)
            ans.push_back(i);
    }
    if(ans.size() != 0) {
        cout << ans.size() << endl;
        for(auto e: ans)
            cout << n[e] << " " << p[e] << endl;
    }
    else {
        if(N == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else
            cout << "There are " << N << " accounts and no account is modified" << endl;
    }
    return 0;
}