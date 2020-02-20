#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


bool palind(string& N) {
    int len = N.size();
    for(int i=0; i<len/2; i++) {
        if(N[i] != N[len-i-1])
            return false;
    }
    return true;
}

int main(void) {
    string N;
    int k;
    cin >> N >> k;
    
    int r = 0;
    while(r<k && !palind(N)) {
        string rev = N;
        reverse(rev.begin(), rev.end());
        int len = N.size();
        vector<int> st(len);
        for(int i=0; i<len; i++)
            st[i] = (N[i]-'0') + (rev[i]-'0');
        for(int i=len-1; i>0; i--) {
            if(st[i] >= 10) {
                st[i-1] += st[i]/10;
                st[i] = st[i]%10;
            }
        }

        if(st[0] >= 10) {
            N = to_string(st[0]/10);
            st[0] = st[0]%10;
        }
        else
            N = "";
        for(int i=0; i<len; i++)
            N += to_string(st[i]);
        r++;
    }
    cout << N <<endl;
    cout << r << endl;
}