#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int sum = 0, cur = 0;
    for(int i = 0; i < n; i ++) {
        int v;
        cin >> v;
        if(v > cur) sum += (v - cur) * 6;
        else if(v < cur) sum += (cur - v) * 4;
        sum += 5;
        cur = v;
    }
    cout << sum << endl;
    
    return 0;
}