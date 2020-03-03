#include<bits/stdc++.h>
using namespace std;

class player {
public:
    int id;
    int weight;
    player() {}
    player(int id, int weight): id(id), weight(weight) {}
};

int main(void) {
    int Np, Ng;
    cin >> Np >> Ng;
    deque<player> players;
    vector<int> weights(Np), orders(Np), rank(Np);
    for(int i=0; i<Np; i++)
        cin >> weights[i];
    for(int i=0; i<Np; i++)
        cin >> orders[i];
    for(int i=0; i<Np; i++)
        players.push_back(player(orders[i], weights[orders[i]]));
    
    vector<vector<player>> res;

    while(!players.empty()) {
        if(players.size() == 1) {
            vector<player> temp;
            temp.push_back(players.front());
            res.push_back(temp);
            break;
        }

        deque<player> winner, match; 
        vector<player> temp;
        while(!players.empty()) {
            int max_w = INT_MIN;
            for(int i=0; i<Ng; i++) {
                if(players.empty())
                    break;
                match.push_back(players.front());
                players.pop_front();
                if(max_w < match.back().weight)
                    max_w = match.back().weight;
            }
            
            while(!match.empty()) {
                if(match.front().weight == max_w) 
                    winner.push_back(match.front());
                else 
                    temp.push_back(match.front());
                match.pop_front();
            }
            
        }
        if(!temp.empty()) {
            res.push_back(temp);
            temp.clear();
        }
        players = winner;
    }
    
    int r = 1;
    for(int i=res.size()-1; i>=0; i--) {
        int r_n = r;
        for(int j=0; j<res[i].size(); j++) {
            rank[res[i][j].id] = r_n;
            r++;
        }
    }

    cout << rank[0];
    for(int i=1; i<Np; i++)
        cout << " " << rank[i];
    return 0;
}