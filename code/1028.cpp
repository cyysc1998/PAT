#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class stu {
public:
    string ID;
    string name;
    int grade;
    stu(string ID, string name, int grade): ID(ID), name(name), grade(grade) {}
};

bool cmp_1(const stu& a, const stu& b) {
    return a.ID < b.ID;
}

bool cmp_2(const stu& a, const stu& b) {
    if(a.name == b.name) 
        return a.ID < b.ID;
    else
        return a.name < b.name;
}

bool cmp_3(const stu& a, const stu& b) {
    if(a.grade == b.grade) 
        return a.ID < b.ID;
    else
        return a.grade < b.grade;
}

int main(void) {
    ios::sync_with_stdio(false);
    vector<stu> stus;
    int N, C;
    string t_id, t_name;
    int t_grade;
    cin >> N >> C;
    for(int i = 0; i < N; i++) {
        cin >> t_id >> t_name >> t_grade;
        stus.push_back(stu(t_id, t_name, t_grade));
    }

    if(C == 1)
        sort(stus.begin(), stus.end(), cmp_1);
    else if(C == 2)
        sort(stus.begin(), stus.end(), cmp_2);
    else if(C == 3)
        sort(stus.begin(), stus.end(), cmp_3);
    
    for(auto e: stus) 
        cout << e.ID << " " << e.name << " " << e.grade << endl;
}