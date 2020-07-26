#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<string>> courses;
int n, k;

int main(void) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++) {
        char s[5];
        int c;
        scanf("%d%s", s, &c);
        for (int j = 0; j < c; j ++) {
            int v;
            scanf("%d", &v);
            courses[v].push_back(s);
        }
    }
    for(int i = 1; i <= k; i ++) {
        auto& stus = courses[i];
        cout << i << " " << stus.size() << endl;;
        sort(stus.begin(), stus.end());
        for(auto& stu: stus)
            cout << stu << endl;
    }
    return 0;
}