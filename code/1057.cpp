#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10 ;

vector<int> t(maxn);
stack<int> sk;

int lowbit(int x) {
    return x&-x;
}

void add(int x, int value) {
    for(int i=x; i<=maxn; i+=lowbit(i))
        t[i] += value;
}

int ask(int x) {
    int sum = 0;
    for(int i=x; i>=1; i-=lowbit(i))
        sum += t[i];
    return sum;
}

int Medium(void) {
    int L = 1, R = maxn;
    int p = (sk.size()+1)/2;

    while(L < R) {
        int M = L+R >> 1;
        if(ask(M) < p)
            L = M + 1;
        else
            R = M; 
    }
    return L;
}


int main(void) {
    
    int N;
    string s;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> s;
        if(s.compare("Pop") == 0) {
            if(sk.empty())
                cout << "Invalid" << endl;
            else {
                cout << sk.top() << endl;
                add(sk.top(), -1);
                sk.pop();
            }
        }
        else if(s.compare("Push") == 0) {
            int t;
            cin >> t;
            sk.push(t);
            add(t, 1);
        }
        else {
            if(sk.empty())
                cout << "Invalid" << endl;
            else {
                cout << Medium() << endl;
            }

        }
    }
    return 0;
}