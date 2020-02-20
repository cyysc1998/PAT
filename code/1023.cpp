#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(void) {
    vector<int> alphas(10);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> c(n);
    for(int i=0; i<n; i++) {
        c[i] = (s[i]-'0')*2;
        alphas[s[i]-'0']++;
    }
    for(int i=n-1; i>0; i--) {
        if(c[i] >= 10) {
            c[i-1] += c[i]/10;
            c[i] = c[i]%10;
        }
    }
    
    bool flag = true;
    if(c[0] >= 10)
        flag = false;
    else {
        for(int i=0; i<n; i++) 
            alphas[c[i]]--;
        for(int i=0; i<=9; i++) 
            if(alphas[i] != 0) {
                flag = false;
                break;
            }
        
    }
    cout << (flag ? "Yes":"No") << endl;
    for(auto e: c)
        cout << e;
}