#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 100010;
unordered_map<int, int> mp;
int g[N], n;

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> g[i];
        mp[g[i]]++;
    }
    for(int i = 0; i < n; i ++) {
        if(mp[g[i]] < 2) {
            cout << g[i] << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    
    return 0;
}