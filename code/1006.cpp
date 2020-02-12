#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

class record{
public:
    string ID;
    string begin;
    string end;
};


bool compare_start(const record& a, const record& b){
    return a.begin < b.begin;
}

int compare_end(const record& a, const record& b){
    return a.end < b.end;
}

int main(void){
    int N;
    cin >> N;
    vector<record> records;
    for(int i = 0; i < N; i++){
        record r;
        cin >> r.ID >> r.begin >> r.end;
        records.push_back(r);
    }

    string start_ID, end_ID;
    sort(records.begin(), records.end(), compare_start);
    start_ID = records.front().ID;
    sort(records.begin(), records.end(), compare_end);
    end_ID = records.back().ID;

    cout << start_ID << " " << end_ID << endl;
}