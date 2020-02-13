#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define max 200000

class score{
public:
    string ID;
    int C, M, E, A;
    score(string ID, int C, int M, int E) : ID(ID), C(C), M(M), E(E){
        A = (C+M+E)/3;
    }
};

bool cmp_c(const score& a, const score& b){
    return a.C > b.C;
}

bool cmp_m(const score& a, const score& b){
    return a.M > b.M;
}

bool cmp_e(const score& a, const score& b){
    return a.E > b.E;
}

bool cmp_a(const score& a, const score& b){
    return a.A > b.A;
}

int main(void){
    vector<score> scores;
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string ID;
        int C, M, E;
        cin >> ID >> C >> M >> E;
        scores.push_back(score(ID, C, M, E));
    }

    vector<score> scores_e(scores);
    vector<score> scores_m(scores);
    vector<score> scores_c(scores);
    vector<score> scores_a(scores);

    sort(scores_e.begin(), scores_e.end(), cmp_e);
    sort(scores_m.begin(), scores_m.end(), cmp_m);
    sort(scores_c.begin(), scores_c.end(), cmp_c);
    sort(scores_a.begin(), scores_a.end(), cmp_a);

    for(int i=0; i<M; i++){
        string t_ID;
        cin >> t_ID;
        int best = max;
        string cs;

        int e = max;
        for(int j=0; j<scores_e.size(); j++){
            if(scores_e.at(j).ID.compare(t_ID)==0){
                e = scores_e.at(j).E;
                break;
            }
        }
        for(int j=0; j<scores_e.size(); j++){
            if(scores_e.at(j).E==e && best >= j+1){
                best = j+1;
                cs = "E";
                break;
            }
        }

        int m = max;
        for(int j=0; j<scores_m.size(); j++){
            if(scores_m.at(j).ID.compare(t_ID)==0){
                m = scores_m.at(j).M;
                break;
            }
        }
        for(int j=0; j<scores_m.size(); j++){
            if(scores_m.at(j).M==m  && best >= j+1){
                best = j+1;
                cs = "M";
                break;
            }
        }

        int c = max;
        for(int j=0; j<scores_c.size(); j++){
            if(scores_c.at(j).ID.compare(t_ID)==0){
                c = scores_c.at(j).C;
                break;
            }
        }
        for(int j=0; j<scores_c.size(); j++){
            if(scores_c.at(j).C==c  && best >= j+1){
                best = j+1;
                cs = "C";
                break;
            }
        }

        int a = max;
        for(int j=0; j<scores_a.size(); j++){
            if(scores_a.at(j).ID.compare(t_ID)==0){
                a = scores_a.at(j).A;
                break;
            }
        }
        for(int j=0; j<scores_a.size(); j++){
            if(scores_a.at(j).A==a  && best >= j+1){
                best = j+1;
                cs = "A";
                break;
            }
        }

        if(e==max && m==max && c==max && a==max)
            cout << "N/A" << endl;
        else
            cout << best << " " << cs << endl;
    }
}