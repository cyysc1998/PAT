#include<bits/stdc++.h>
using namespace std;

bool valid(deque<int>& nums, int M) {
    int N = nums.size();
    stack<int> s;
    int ele = 1;
    while(true) {
        s.push(ele++);
        if(s.size() > M)
            return false;
        while(!s.empty()) {
            if(s.top() == nums.front()) {
                s.pop();
                nums.pop_front();
            } 
            else
                break;
        }
        if(nums.empty())
            return true;
    }
}

int main(void) {
    int M, N, K;
    cin >> M >> N >> K;
    int t;
    for(int i=1; i<=K; i++) {
        deque<int> nums;
        for(int j=0; j<N; j++) {
            cin >> t;
            nums.push_back(t);
        }
        cout << (valid(nums, M) ? "YES" : "NO") << endl;
    }
    return 0;
}