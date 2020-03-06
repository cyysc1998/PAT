#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    if(N == 1)
        cout << "1=1" << endl;
    else
        cout << N << "=";
    vector<bool> prime;
    prime = vector<bool>(sqrt(N)+1, true);
    for(int i = 2; i <= sqrt(N); i++) {
        for(int j = 2; j*i <= sqrt(N); j++)
            prime[i*j] = false;
    }
    int factor = 2;
    while(N != 1) {
        int s = 0;
        while(N%factor == 0) {
            s++;
            N /= factor;
        }
        if(s==1) 
            cout << factor << (N==1 ? "" : "*");
        else if(s>1) 
            cout << factor << "^" << s << (N==1 ? "" : "*");

        factor++;
        while(!prime[factor]) 
            factor++; 
    }
    return 0;
}