#include<bits/stdc++.h>
using namespace std;

class peo {
public:
    string name;
    int age;
    int worth;
    peo(string name, int age, int worth): name(name), age(age), worth(worth) {}
};

bool cmp(const peo &a, const peo &b) {
    if(a.worth == b.worth && a.age == b.age)
        return a.name < b.name;
    else if(a.worth == b.worth)
        return a.age < b.age;
    else
        return a.worth > b.worth; 
}

int main(void) {
    int N, K;
    vector<peo> peos;

    string name;
    int age, worth;
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> name >> age >> worth;
        peos.push_back(peo(name, age, worth));
    }

    sort(peos.begin(), peos.end(), cmp);

    int M, Amin, Amax;
    for(int i=0; i<K; i++) {
        cin >> M >> Amin >> Amax;
        cout << "Case #" << i+1 << ":" << endl;
        bool flag = false;
        int count = 0;
        for(int i=0; i<N; i++) {
            if(peos[i].age >= Amin && peos[i].age < Amax) {
                cout << peos[i].name << " " << peos[i].age << " " << peos[i].worth << endl;
                flag = true;
                count++;
            }
            if(count == M)
                break;
        }
        if(!flag)
            cout << "None" << endl;
    }
    return 0;
}