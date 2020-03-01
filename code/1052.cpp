#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int addr;
    int key;
    int next;
    node() {}
    node(int addr, int key, int next) : addr(addr), key(key), next(next) {}
};

bool cmp(const node& a, const node& b) {
    return a.key < b.key;
}

int main(void) {
    vector<node> f(100500);
    vector<node> s;
    int N, st;
    scanf("%d%d", &N, &st);
    int a_, k_, n_;
    for(int i=0; i<N; i++) {
        scanf("%d%d%d", &a_, &k_, &n_);
        f[a_] = node(a_, k_, n_);
    }
    while(st != -1) {
        s.push_back(f[st]);
        st = f[st].next;
    }
    sort(s.begin(), s.end(), cmp);
    if(s.size() == 0)
        printf("0 -1\n");
    else if(s.size() == 1) {
        printf("1 %05d\n", s.front().addr);
        printf("%05d %d -1\n", s.front().addr, s.front().key);
    }
    else {
        printf("%d %05d\n", s.size(), s.front().addr);
        for(int i=0; i<s.size()-1; i++)
            printf("%05d %d %05d\n", s[i].addr, s[i].key, s[i+1].addr);
        printf("%05d %d -1\n", s[s.size()-1].addr, s[s.size()-1].key);
    }
    return 0;
}