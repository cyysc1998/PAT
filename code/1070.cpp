#include<bits/stdc++.h>
using namespace std;

class cake {
public:
    double storage;
    double price;
    double per;
};

bool cmp(const cake& a, const cake& b) {
    return a.per > b.per;
}

int main(void) {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<cake> m(N);
    double s;
    double p;
    for(int i=0; i<N; i++) {
        scanf("%lf", &s);
        m[i].storage = s;
    }
    for(int i=0; i<N; i++) {
        scanf("%lf", &p);
        m[i].price = p;
        m[i].per = p/m[i].storage;
    }
    sort(m.begin(), m.end(), cmp);

    double sum = 0;
    for(int i=0; i<m.size() && M!=0; i++) {
        int subs = m[i].storage > M ? M : m[i].storage;
        M -= subs;
        sum += 1.0*subs*m[i].per;
    }
    printf("%.2lf\n", sum);
    return 0;
}