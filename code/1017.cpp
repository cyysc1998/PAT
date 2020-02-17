#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class cust {
public:
    int arrive;
    int work;
    cust(string a, int w) {
        arrive = stoi(a.substr(0,2))*60*60 + stoi(a.substr(3,5))*60 + stoi(a.substr(6,7));
        work = w*60;
    }
};

bool cmp(const cust& a, const cust& b) {
    return a.arrive < b.arrive;
}

int main(void) {
    int N, K;
    cin >> N >> K;
    vector<cust> custs;
    vector<int> windows(K, 8*3600);
    string t_arrive;
    int t_work;
    for(int i=0; i<N; i++) {
        cin >> t_arrive >> t_work;
        if(t_arrive <= "17:00:00")  
            custs.push_back(cust(t_arrive, t_work));
    }
    sort(custs.begin(), custs.end(), cmp);

    double total = 0;

    for(auto c: custs) {
        int min_index = 0;
        for(int i=1; i<windows.size(); i++) {
            if(windows[i] < windows[min_index])
                min_index = i;
        }

        if(windows[min_index] > c.arrive) {
            total += (windows[min_index] - c.arrive);
            windows[min_index] += c.work;
        }
        else
            windows[min_index] = c.arrive + c.work;
    }
    if(custs.size() == 0)
        cout << "0.0" << endl;
    else 
        cout << fixed << setprecision(1) << total/custs.size()/60 << endl;
}