#include<bits/stdc++.h>
using namespace std;

vector<string> trans(string s, int N) {
    int z = 0;
    for(int i=0; i<s.size(); i++)
        if(s[i]!='0' && s[i]!='.')
            z = 1;
    if(!z)
        return {"0", "0"};
    int k = 0;
    while(k<s.size() && s[k]=='0' && s[k+1]!='.') k++;
    s = s.substr(k);
    
    int pos = s.find('.');
    if(pos == -1) {
        int border = min(N, (int)s.size());
        return {s.substr(0, border),  to_string(s.size())};
    }
    else {
        if(s[0] != '0') {
            if(pos >= N)
                return {s.substr(0, N),  to_string(pos)};
            else {
                string res = s.substr(0, pos);
                if(s.size()-1 >= N)
                    return {res+s.substr(pos+1, N-pos), to_string(pos)};
                else {
                    res += s.substr(pos+1);
                    return {res, to_string(pos)};
                }
            }
        }
        else {
            int t = 0;
            while(s[t]=='.' || s[t]=='0') t++;
            int border = min(N, (int)s.size()-t);
            return {s.substr(t, border), to_string(pos-t+1)};
        }
    }
}


int main(void) {
    int N;
    string a, b;
    cin >> N >> a >> b;
    vector<string> res1 ,res2;
    res1 = trans(a, N);
    res2 = trans(b, N);
    while(res1[0].size() < N) res1[0] += "0";
    while(res2[0].size() < N) res2[0] += "0";
    if(res1 == res2)
        cout << "YES" << " 0." << res1[0] << "*10^" << res1[1] << endl;
    else
        cout << "NO" << " 0." << res1[0] << "*10^" << res1[1] << " 0." << res2[0] << "*10^" << res2[1] << endl;
    return 0;
}

