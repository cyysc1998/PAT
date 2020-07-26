#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

bool is_prime(int n) {
    if(n == 2)
        return false;
    for(int i = 2; i <= n / i; i ++)
        if(n % i == 0)
            return false;
    return true;
}

void dfs(int digit_nums, int sum, int cur, vector<int>& res) {
    if(digit_nums == k && sum == m) {
        res.push_back(cur);
        return;
    }
    if(digit_nums > k || sum == m)
        return;
    
    for(int i = 0; i <= 9; i ++) 
        dfs(digit_nums + 1, sum + i, cur * 10 + i, res);
    
}

int get_sum(int n) {
    int sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> k >> m;
        cout << "Case " << i << endl;
        vector<int> nums;
        dfs(0, 0, 0, nums);
        bool is_find = false;
        for(auto num: nums) {
            int _n = get_sum(num + 1);
            int t_c = gcd(m, _n);
            if(t_c > 2 && is_prime(t_c)) {
                cout << _n << " " << num << endl;
                is_find = true;
            }
        }
        if(!is_find) 
            cout << "No Solution" << endl;
    }
    return 0;
}