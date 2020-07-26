#include<bits/stdc++.h>
using namespace std;

class point {
public:
    int id;
    int minDist;
    bool known;
    map<int, int> neighs;
    point(): minDist(INT_MAX), known(false) {}
};

int getID(string s, int N) {
    if(s[0]>='0' && s[0]<='9')
        return stoi(s);
    else
        return stoi(s.substr(1)) + N;
}


int main(void) {
    int N, M, K, D;
    cin >> N >> M >> K >> D;
    vector<point> points(N+M+1);
    string t1, t2;
    int dis;
    for(int i=1; i<=K; i++) {
        cin >> t1 >> t2 >> dis;
        points[getID(t1, N)].neighs[getID(t2, N)] = dis;
        points[getID(t2, N)].neighs[getID(t1, N)] = dis;
    }
    for(int i=1; i<=M+N; i++)
        points[i].id = i;
    
    int minRes = INT_MAX;
    int min_dis = INT_MIN;
    double aver_dis = 0;
    for(int index=N+1; index<=M+N; index++) {
        for(int i=1; i<=N+M; i++) {
            points[i].known = false;
            points[i].minDist = INT_MAX;
        }
        point& s = points[index];
        s.known = true;
        s.minDist = 0;
        for(auto& e: s.neighs) 
            points[e.first].minDist = e.second;

        int k_n = 1;
        while(k_n < N+M) {
            int t = 1;
            while(points[t].known && t <= N+M) t++;
            for(int i=t; i<=N+M; i++) {
                if(!points[i].known && points[i].minDist < points[t].minDist)
                    t = i;
            }
           
            points[t].known = true;
            for(auto& e: points[t].neighs) {
                if(points[e.first].minDist > points[t].minDist + e.second)
                    points[e.first].minDist = points[t].minDist + e.second;
            }
            k_n++;
        }
        int curmin = INT_MAX, curmax = INT_MIN;
        double average = 0;
        for(int i=1; i<=N; i++) {
            curmin = min(curmin, points[i].minDist);
            curmax = max(curmax, points[i].minDist);
            average += points[i].minDist;
        }
        average /= N;
        if(curmax > D)
            continue;
        if(curmin > min_dis || (curmin == min_dis && average < aver_dis)) {
            minRes = index;
            min_dis = curmin;
            aver_dis = average;
        }
    }
    if(minRes == INT_MAX)
        cout << "No Solution" << endl;
    else {
        cout << "G" << minRes-N << endl;
        cout << fixed << setprecision(1) << 1.0*min_dis << " " << fixed << setprecision(1) << aver_dis << endl;
    }
    return 0;
}