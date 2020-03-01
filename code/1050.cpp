#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    map<char, int> f;
    for(int i=0; i<b.size(); i++)
        f[b[i]] = 1;
    for(int i=0; i<a.size(); i++)
        if(f[a[i]] != 1)
            cout << a[i];
    return 0;
}