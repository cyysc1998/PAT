## 7-1 Sexy Primes (20分)
```c++
#include <iostream>

using namespace std;

int n;

bool is_prime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= n / i; i++)
		if (n % i == 0) return false;
	return true;
}

bool judge(int n) {
	if (is_prime(n)) {
		if (is_prime(n - 6)) return true;
		if (is_prime(n + 6)) return true;
	}
	return false;
}

int main(void) {
	cin >> n;
	if (judge(n)) {
		puts("Yes");
		if (is_prime(n - 6)) cout << n - 6 << endl;
		else cout << n + 6 << endl;
	}
	else {
		puts("No");
		int t = n + 1;
		while (!judge(t)) t++;
		cout << t << endl;
	}
	return 0;
}
```

## 7-2 Anniversary (25分)
```c++
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> alumni;
int res;
string alummu, guest;
int n, m;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		alumni.insert(s);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		string birth = s.substr(6, 8);
		if (alumni.count(s)) {
			res++;
			if (alummu.empty() || alummu.substr(6, 8) > birth)
				alummu = s;
		}
		else {
			if (guest.empty() || guest.substr(6, 8) > birth)
				guest = s;
		}
	}
	cout << res << endl;
	if (!alummu.empty()) cout << alummu << endl;
	else cout << guest << endl;

	return 0;
}
```

## 7-3 Telefraud Detection (25分)
```c++
#include <iostream>
#include <cstring>
#include <unordered_set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1010;
int g[N][N];
int p[N];
unordered_set<int> person;
int k, n, m;

int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main(void) {
	cin >> k >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		g[a][b] = g[a][b] + v;
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (g[i][j] && g[i][j] <= 5)
				cnt++;
		}
		if (cnt > k) {
			int recall = 0;
			for (int j = 1; j <= n; j++) {
				if (g[i][j] && g[i][j] <= 5 && g[j][i])
					recall++;
			}
			if (cnt >= recall * 5)
				person.insert(i);
		}
	}
	if (person.empty()) {
		cout << "None" << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
		p[i] = i;
	map<int, vector<int>> res;
	for (auto e : person) {
		for (int i = 1; i <= n; i++) {
			if (person.count(i) && g[e][i] && g[i][e]) {
				int x = find(e), y = find(i);
				if (x > y) swap(x, y);
				if (x != y)
					p[y] = x;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (person.count(i)) {
			res[find(i)].push_back(i);
		}
	}

	for (auto& e : res) {
		auto& p = e.second;
		sort(p.begin(), p.end());
		cout << p[0];
		for (int i = 1; i < p.size(); i++)
			cout << " " << p[i];
		cout << endl;
	}
	return 0;
}
```

## 7-4 Structure of a Binary Tree (30分)
```c++
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

const int N = 40;
unordered_map<int, int> l, r, pos, p;
int post[N], inorder[N];
int n, m;

int build(int il, int ir, int pl, int pr) {
	int root = post[pr];
	int k = pos[root];

	if (il < k) {
		int lroot = build(il, k - 1, pl, pl + (k - 1 - il));
		l[root] = lroot;
		p[lroot] = root;
	}
	if (k < ir) {
		int rroot = build(k + 1, ir, pl + (k - 1 - il) + 1, pr - 1);
		r[root] = rroot;
		p[rroot] = root;
	}
	return root;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> post[i];
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		pos[inorder[i]] = i;
	}
	int root = build(0, n - 1, 0, n - 1);
	p[root] = -1;
	bool is_full = true;
	for (int i = 0; i < n; i++) {
		int t = inorder[i];
		if (l.count(t) == 0 && r.count(t) != 0 || l.count(t) != 0 && r.count(t) == 0) {
			is_full = false;
			break;
		}
	}
	cin >> m;
	getchar();
	while (m--) {
		string query;
		getline(cin, query);
		stringstream ssin(query);
		if (query.back() == 't') {
			int t;
			ssin >> t;
			if (t == root) puts("Yes");
			else puts("No");
		}
		else if (query.back() == 's') {
			int a, b;
			string t;
			ssin >> a >> t >> b;
			if (p[a] == p[b]) puts("Yes");
			else puts("No");
		}
		else if (query.back() == 'l') {
			int a, b;
			string t;
			ssin >> a >> t >> b;
			int ha = 0, hb = 0;
			while (p[a] != -1) {
				a = p[a];
				ha++;
			}
			while (p[b] != -1) {
				b = p[b];
				hb++;
			}
			if (ha == hb) puts("Yes");
			else puts("No");
		}
		else if (query.back() == 'e') {
			if (is_full)puts("Yes");
			else puts("No");
		}
		else {
			int a, b;
			string s1, s2, s3, s4, s5;
			ssin >> a >> s1 >> s2 >> s3;
			if (s3 == "parent") {
				ssin >> s4 >> b;
				if (p[b] == a) puts("Yes");
				else puts("No");
			}
			else if (s3 == "left") {
				ssin >> s4 >> s5 >> b;
				if (l[b] == a) puts("Yes");
				else puts("No");
			}
			else if (s3 == "right") {
				ssin >> s4 >> s5 >> b;
				if (r[b] == a)puts("Yes");
				else puts("No");
			}
		}
	}
	return 0;
}
```
