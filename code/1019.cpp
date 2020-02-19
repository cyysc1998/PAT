#include<iostream>
#include<vector>
using namespace std;

bool palind(vector<int>& d) {
    int N = d.size();
    for (int i=0; i<N/2; i++) {
        if (d[i] != d[N-i-1])
            return false;
    }
    return true;
}

int main(void) {
    int N, base;
    cin >> N >> base;
    vector<int> digit;

    if (N == 0) { 
        cout << "Yes" << endl;
        cout << 0 << endl;
        return 0;
    }
    
    while (N != 0) {
        int r = N % base;
        N /= base;
        digit.push_back(r);
    }
    bool res = palind(digit);
    
    cout << (res ? "Yes" : "No") << endl;
    cout << digit[digit.size()-1];
    if (digit.size() > 1) {
        for (int i=digit.size()-2; i>=0; i--)
            cout << " " << digit[i];
    }
    return 0;
}