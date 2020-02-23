#include<iostream>
#include<map>
#include<climits>
#include<iomanip>
using namespace std;

class node {
public:
    char data;
    int next;
    int times;
    node() {}
    node(char data, int next) : data(data), next(next), times(0) {}
};

int main(void) {
    int w1, w2, N;
    ios::sync_with_stdio(false);
    cin >> w1 >> w2 >> N;
    map<int, node> nodes;
    char temp_data;
    int temp_addr, temp_next;
    for(int i = 0; i < N; i++) {
        cin >> temp_addr >> temp_data >> temp_next;
        nodes[temp_addr] = node(temp_data, temp_next);
    }
    int temp = w1;
    while(temp != -1) {
        nodes[temp].times++;
        temp = nodes[temp].next;
    }
    int res = INT_MAX;
    temp = w2;
    while(temp != -1) {
        if(nodes[temp].times != 0) {
            res = temp;
            break;
        }
        else {
            nodes[temp].times++;
            temp = nodes[temp].next;
        }
    }

    if(res != INT_MAX) 
        cout << setw(5) << setfill('0') << res << endl;
    else
        cout << "-1" << endl;
}