#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;

typedef long long int lu;

int main(void) {
    int N;
    deque<lu> s1, s2;
    vector<lu> s;
    cin >> N;

    lu temp;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &temp);
        s1.push_back(temp);
    }
    cin >> N;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &temp);
        s2.push_back(temp);
    }

    while(!s1.empty() && !s2.empty()) {
        if(s1.front() <= s2.front()) {
            s.push_back(s1.front());
            s1.pop_front();
        }
        else {
            s.push_back(s2.front());
            s2.pop_front();
        }
    }
    while(!s1.empty()) {
        if(s1.front() != s.back()) {
            s.push_back(s1.front());
            s1.pop_front();
        }
    }

    while(!s2.empty()) {
        if(s2.front() != s.back()) {
            s.push_back(s2.front());
            s2.pop_front();
        }
    }

    if(s.size()%2 == 0)
        cout << s[s.size()/2-1] << endl;
    else
        cout << s[s.size()/2] << endl;
}