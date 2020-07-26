#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int age;
    int worth;
    bool operator< (const Person& p) {
        if (worth != p.worth) return worth > p.worth;
        else if (age != p.age) return age < p.age;
        return name < p.name;
    }
};

vector<Person> persons;
int n, k;

int main(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        char name[20];
        int age, worth;
        scanf("%s%d%d", name, &age, &worth);
        persons.push_back({name, age, worth});
    }
    
    sort(persons.begin(), persons.end());
    for (int i = 1; i <= k; i ++) {
        int m, amin, amax;
        scanf("%d%d%d", &m, &amin, &amax);
        printf("Case #%d:\n", i);
        int t = 0;
        for (auto& p: persons) {
            int age = p.age;
            if (age >= amin && age <= amax) {
                cout << p.name << " " << p.age << " " << p.worth << endl;
                t++;
            }
            if (t == m)
                break;
        }
        if (t == 0)
            cout << "None" << endl;
    }
    return 0;
}