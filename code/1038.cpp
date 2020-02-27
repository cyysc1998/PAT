#include<bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    return a+b < b+a;
}

int main(void) {
    int N;
    cin >> N;
    vector<string> s(N);
    for(int i=0; i<N; i++)
        cin >> s[i];
    sort(s.begin(), s.end(), cmp);
    string t;
    for(auto e: s)
        t += e;
    int i = 0;
    while(t[i] == '0' && i != t.size()-1)
        i++;
    cout << t.substr(i) << endl;
    return 0;
}