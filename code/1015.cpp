#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool isPrime(int n) {
    if(n <= 1)
        return false;
    int k = sqrt(n);
    for(int i=2; i<=k; i++) {
        if(n%i == 0) 
            return false;
    }
    return true;
}

int main(void) {
    int N, radix;
    while(cin >> N && N > 0) { 
        cin >> radix;
        if(!isPrime(N)) {
            cout << "No" << endl;
            continue;
        }
        vector<int> d;
        int r;
        while(N != 0) {
            r = N%radix;
            N = N/radix;
            d.push_back(r);
        }
        reverse(d.begin(), d.end());
        int r_N = 0;
        for(int i = 0; i < d.size(); i++) {
            r_N += d[i]*pow(radix, i);
        }
        if(isPrime(r_N)) 
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}