#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<map>
using namespace std;

class record {
public:
    string time;
    string type; 
    record();
    record(string time, string type): time(time), type(type) {}
};

bool cmp(const record& a, const record& b) {
    return a.time < b.time;
}

int main(void) {
    int price[24];
    int N;
    map<string, vector<record>, less<string> > custs;
    int day = 0;
    for(int i=0; i<24; i++) {
        cin >> price[i];
        day += price[i]*60;
    }
    string name, time, type;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> name >> time >> type;
        if(custs.find(name) == custs.end()) {
            custs[name] = vector<record>();
        }
        custs[name].push_back(record(time, type));
    }
    map<string, vector<record> >:: iterator it;
    for(it = custs.begin(); it != custs.end(); it++) {
        sort(it->second.begin(), it->second.end(), cmp);
        bool isAccepted = false;
        bool pair = false;
        string begin, end;
        double total = 0;
        for(auto r: it->second) {
            if(r.type.compare("on-line") == 0) {
                pair = true;
                begin = r.time.substr(3);
            }
            else if(r.type.compare("off-line")==0 && pair) {
                if(!isAccepted) {
                    cout << it->first << " " << it->second.front().time.substr(0, 2) << endl;
                    isAccepted = true;
                }
                pair = false;
                end = r.time.substr(3);
                cout << begin << " " << end << " ";
                int m = 0;
                int minus = (stoi(end.substr(0,2))-stoi(begin.substr(0,2))) *24*60 + \
                            (stoi(end.substr(3,5))-stoi(begin.substr(3,5))) *60 + \
                            (stoi(end.substr(6,8))-stoi(begin.substr(6,8)));
                cout << minus << " ";

                int be_d = stoi(begin.substr(0, 2)), en_d = stoi((end.substr(0, 2)));
                int be_h = stoi(begin.substr(3, 5)), en_h = stoi(end.substr(3, 5));
                
                for(int i=be_d; i<en_d; i++) {
                    m += day;
                }
                if(be_h > en_h) {
                    int comple = 0;
                    for(int i=be_h + 1; i<en_h + 24; i++)
                        comple += price[i%24] * (60);
                    comple += stoi(end.substr(6,8))*price[en_h] +(60-stoi(begin.substr(6,8)))*price[be_h];
                    m = m + comple - day;
                }
                else if(be_h < en_h) {
                    for(int i=be_h + 1; i<en_h; i++)
                        m += price[i] * (60);
                    m = m + stoi(end.substr(6,8))*price[en_h] +(60-stoi(begin.substr(6,8)))*price[be_h];
                }
                else 
                    m = m + (stoi(end.substr(6,8))-stoi(begin.substr(6,8)))*price[en_h];
                total += 0.01*m;
                cout << fixed << setprecision(2) << "$" << 0.01*m << endl;
            }
        }
        if(total != 0.0)
            cout << "Total amount: $" << fixed << setprecision(2) << total << endl;
    }
}

// Another method to calculate the time and fee
// int be_day=stoi(begin.substr(0,2)), be_hour = stoi(begin.substr(3,5)), be_minute=stoi(begin.substr(6,8));
// int en_day=stoi(end.substr(0,2)), en_hour = stoi(end.substr(3,5)), en_minute=stoi(end.substr(6,8));
// while (be_day!=en_day || be_hour!=en_hour || be_minute!=en_minute){
//     m += price[be_hour];
//     be_minute++;
//     if (be_minute==60){
//         be_hour++;
//         be_minute=0;
//     }
//     if (be_hour==24){
//         be_day++;
//         be_hour=0;
//     }
// }
                