#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<climits>
using namespace std;

class station {
public:
    double dis;
    double price;
    station() {}
};

bool cmp(const station& a, const station& b) {
    if(a.dis == b.dis)
        return a.price > b.price;
    else
        return a.dis < b.dis;
}

int main(void) {
    double Cmax, D, Davg;
    int N;
    cin >> Cmax >> D >> Davg >> N;
    vector<station> S(N+1);
    double temp_dis, temp_price;
    for(int i=0; i<N; i++) {
        cin >> temp_price >> temp_dis;
        S[i].price = temp_price;
        S[i].dis = temp_dis;
    }
    
    S[N].dis = D;
    S[N].price = 0;

    sort(S.begin(), S.end(), cmp);
    int curID = 0;
    double curDis = 0, curPrice = S[0].price, Cleft = 0;
    double money = 0;
    double Radiu = Cmax * Davg;

    if(S[0].dis != 0.0) {
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }

    while(curDis < D) {
        
        if(curDis + Radiu < S[curID+1].dis) {
            cout << "The maximum travel distance = " << fixed << setprecision(2) << curDis+Radiu << endl;
            return 0;
        }
        else {
            bool flag = false;
            int low_ID = curID + 1;
            int range = curDis + Radiu;
            for(int i=low_ID; i<=N && range >= S[i].dis; i++) {
                if(S[i].price < S[low_ID].price) 
                    low_ID = i;
                if(S[i].price < curPrice) {
                    low_ID = i;
                    flag = true;
                    break;
                }

            }
            if(flag) {
                money += ((S[low_ID].dis - S[curID].dis)/Davg - Cleft)*curPrice;
                Cleft = 0;
            }
            else {
                money += (Cmax - Cleft)*curPrice;
                Cleft = Cmax - (S[low_ID].dis - S[curID].dis)/Davg;
            }
            curID = low_ID;
            curPrice = S[low_ID].price;
            curDis = S[low_ID].dis;
        }
    }
    cout << fixed << setprecision(2) << money << endl;
}