#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class stu {
public:
    int seq;
    string ID;
    int scores;
    int d_rank;
    int a_rank;
    stu(int seq, string id, int scores): seq(seq), ID(id), scores(scores) {}
};

bool cmp(const stu& a, const stu& b) {
    if(a.scores == b.scores) 
        return a.ID < b.ID;
    else
        return a.scores > b.scores;
}

int main(void) {
    int N;
    cin >> N;
    vector<stu> a_rank;
    vector<vector<stu>> d_rank(N);
    for(int i=0; i<N; i++) {
        int K;
        cin >> K;
        string t_id;
        int t_score;
        for(int j=0; j<K; j++) {
            cin >> t_id >> t_score;
            d_rank[i].push_back(stu(i+1, t_id, t_score));
        }
    }

    for(auto& e: d_rank) {
        sort(e.begin(), e.end(), cmp);
        for(int i=0; i<e.size(); i++) {
            
            if(i!=0 && e[i].scores == e[i-1].scores)
                e[i].d_rank = e[i-1].d_rank;
            else
                e[i].d_rank = i+1;
        }
    }
    
    for(auto& e: d_rank) {
        for(auto r: e)
            a_rank.push_back(r);
    }

    sort(a_rank.begin(), a_rank.end(), cmp);
    for(int i=0; i<a_rank.size(); i++) {
        if(i!=0 && a_rank[i].scores == a_rank[i-1].scores)
            a_rank[i].a_rank = a_rank[i-1].a_rank;
        else
            a_rank[i].a_rank = i+1;
    }
    cout << a_rank.size() << endl;
    for(int i=0; i<a_rank.size(); i++) 
        cout << a_rank[i].ID << " " << a_rank[i].a_rank << " " << a_rank[i].seq << " " << a_rank[i].d_rank << endl;
}