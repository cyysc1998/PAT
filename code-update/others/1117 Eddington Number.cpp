#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;
int n;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int v;
        cin >> v;
        p.push_back(v);
    }
    sort(p.rbegin(), p.rend());
    int res = 0;
    for (int i = 1; i <= n; i ++) {
        if (i >= p[i - 1]) 
            break;
        res = i;
    }
    cout << res << endl;
    
    return 0;
}