#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;
vector<vector<int>> res;
vector<int> order;
int w[N];
int np, ng;

int main(void) {
    cin >> np >> ng;
    for (int i = 0; i < np; i ++)
        cin >> w[i];
    for (int i = 0; i < np; i ++) {
        int v;
        cin >> v;
        order.push_back(v);
    }
    
    while (!order.empty()) {
        vector<int> t;
        for(int i = )
    }
}