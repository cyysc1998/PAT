#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int N = 31 * 24 * 60 + 10;
double cost[24];
double sum[N];
int n;

struct Record {
    string time;
    int minutes;
    string state;
    bool operator< (const Record& r) const {
        return minutes < r.minutes;
    }
};

int main(void) {
    for (int i = 0; i < 24; i ++) cin >> cost[i];
    for (int i = 1; i < N; i ++) sum[i] = sum[i - 1] + cost[(i - 1) % 1440 / 60] / 100;

    map<string, vector<Record>> persons;
    cin >> n;
    int month, day, hour, minute;
    for (int i = 0; i < n; i ++) {
        char name[30], state[10], time[20];
        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, state);
        sprintf(time, "%02d:%02d:%02d", day, hour, minute);
        int minutes = (day - 1) * 1440 + hour * 60 + minute;
        persons[name].push_back({time, minutes, state});
    }

    for (auto& person: persons) {
        double total = 0;
        string name = person.first;
        auto& r = person.second;
        sort(r.begin(), r.end());

        for (int i = 0; i < r.size() - 1; i ++) {
            auto a = r[i], b = r[i + 1];
            if (a.state == "on-line" && b.state == "off-line") {
                if (!total)
                    printf("%s %02d\n", name.c_str(), month);
                printf("%s %s %d $%.2lf\n", a.time.c_str(), b.time.c_str(), b.minutes - a.minutes, sum[b.minutes] - sum[a.minutes]);
                total += sum[b.minutes] - sum[a.minutes];
            }
        }
        if (total)
            printf("Total amount: $%.2lf\n", total);
    }
    return 0;
}