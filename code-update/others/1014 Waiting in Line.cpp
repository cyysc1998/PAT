#include <iostream>

using namespace std;

const int N = 30, K = 1010;
int come[K], finish[K], finish_time = 17 * 60;
int n, m, k, q;

struct window {
    int nums;
    int next_time;
    window() {nums = 0, next_time = 8 * 60;}
} windows[N];


int main(void) {
    cin >> n >> m >> k >> q;
    for(int i = 1; i <= k; i ++) {
        int serve_time;
        cin >> serve_time;
        int id = 1;
        for(int j = 1; j <= n; j++) {
            if(windows[id].next_time > windows[j].next_time)
                id = j;
        }
        if(windows[id].next_time >= finish_time)
            finish[i] = -1;
        else {
            finish[i] = windows[id].next_time + serve_time;
            windows[id].next_time = finish[i];
        }
    }
    while( q-- ) {
        int id;
        cin >> id;
        if(finish[id] == -1)
            cout << "Sorry" << endl;
        else 
            printf("%02d:%02d\n", finish[id]/60, finish[id]%60);
    }
    return 0;
}