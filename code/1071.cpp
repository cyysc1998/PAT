#include<bits/stdc++.h>
using namespace std;

bool isnumalpha(char c) {
    if(c>='0' && c<='9' || c>='A' && c<='Z' || c>='a' && c <='z') 
        return true;
    else
        return false;
}

int main(void) {
    map<string, int, less<string>> s;
    string t;
    getline(cin, t);
    for(int i=0; i<t.size(); i++) {
        if(!isnumalpha(t[i]))
            t.replace(i, 1, " ");
    }
    transform(t.begin(), t.end(), t.begin(), towlower);
    t = t + " ";
    int p = 0, q = 0;
    bool pair = false;
    while(p < t.size()) {
        if(!isnumalpha(t[p]) && pair) {
            pair = false;
            s[t.substr(q, p-q)]++;
        }
        if(isnumalpha(t[p]) && !pair) {
            pair = true;
            q = p;
        }
        p++;
    }

    int max_t = INT_MIN;
    for(auto& e: s) 
        max_t = max(max_t, e.second);
    for(auto& e: s) {
        if(e.second == max_t) {
            cout << e.first << " " << e.second << endl;
            break;
        }
    }
    return 0;
}