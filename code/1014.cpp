#include<iostream>
#include<deque>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;

class cust {
public:
    int ID; 
    int l_time;
    int s_time;
    int t_end;
    cust(int t, int l): ID(t), s_time(l), l_time(l) {}
};

bool isFull(vector<deque<cust> >& lines, int m) {
    for(int i=0; i<lines.size(); i++) {
        if(!(lines[i].size()==m))
            return false;
    }
    return true;
}

int main(void) {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    vector<deque<cust> > lines(N);
    deque<cust> custs;
    map<int, int> ans;
    vector<int> query;

    int t_cust;
    for(int i=0; i<K; i++) {
        cin >> t_cust;
        custs.push_back(cust(i, t_cust));
    }
    int t_query;
    for(int i=0; i<Q; i++) {
        cin >> t_query;
        query.push_back(t_query);
    }

    for(int t=1; t<=540; t++) {
        while(!isFull(lines, M) && !custs.empty()) {
            int short_line = 0;
            for(int i=0; i<lines.size(); i++) {
                if(lines[i].size() < lines[short_line].size())
                    short_line = i;
            }
            lines[short_line].push_back(custs.front());
            custs.pop_front();
        }


        for(int i=0; i<lines.size(); i++) {
            if(!lines[i].empty()) {
                lines[i].front().l_time--;
                if(lines[i].front().l_time == 0) {
                    lines[i].front().t_end = t;
                    ans.insert(map<int, int>:: value_type(lines[i].front().ID+1, lines[i].front().t_end));
                    lines[i].pop_front();
                }
            }
        }
    }
    for(int i=0; i<lines.size(); i++) {
        if(!lines[i].empty() && lines[i].front().l_time != lines[i].front().s_time) {
            lines[i].front().t_end = 540 + lines[i].front().l_time;
            ans.insert(map<int, int>::value_type(lines[i].front().ID+1, lines[i].front().t_end));
        }
    }
    for(int i=0; i<query.size(); i++) {
        if(ans.find(query[i]) == ans.end()) 
            cout << "Sorry" << endl;
        else
            cout << setw(2) << setfill('0') << 8 + ans[query[i]]/60 << ":" << setw(2) << setfill('0') << ans[query[i]]%60 << endl;
    }

}