#include<bits/stdc++.h>
using namespace std;

class stu {
public:
    string name;
    string id;
    string gender;
    int grade;
    stu(string name, string gender, string id, int grade): name(name), gender(gender), id(id), grade(grade) {}
};

bool cmp_f(const stu& a, const stu& b) {
    return a.grade > b.grade;
}

bool cmp_m(const stu& a, const stu& b) {
    return a.grade < b.grade;
}

int main(void) {
    int N;
    cin >> N;
    vector<stu> f, m;
    string s1, s2, s3;
    int g;
    for(int i=0; i<N; i++) {
        cin >> s1 >> s2 >> s3 >> g;
        if(s2.compare("M") == 0)
            m.push_back(stu(s1, s2, s3, g));
        else
            f.push_back(stu(s1, s2, s3, g));
    }
    sort(m.begin(), m.end(), cmp_m);
    sort(f.begin(), f.end(), cmp_f);
    if(!f.empty())
        cout << f.front().name << " " << f.front().id << endl;
    else
        cout << "Absent" << endl;
    if(!m.empty())
        cout << m.front().name << " " << m.front().id << endl;
    else
        cout << "Absent" << endl;
    if(f.empty() || m.empty())
        cout << "NA" << endl;
    else
        cout << f.front().grade - m.front().grade << endl;
    return 0;
}