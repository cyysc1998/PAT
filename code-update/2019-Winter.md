## 7-1 Good in C (20分)
```c++
#include <iostream>
#include <sstream>

using namespace std;

char alphas[26][7][5];

void print(string s) {
	for (int p = 0; p < 7; p++) {
		bool is_first = true;
		for (int i = 0; i < s.size(); i++) {
			if (is_first) is_first = false;
			else cout << " ";
			for (int j = 0; j < 5; j++) 
				cout << alphas[s[i] - 'A'][p][j];
		}
		cout << endl;
	}	
}

int main(void) {
	string s;
	for (int i = 0; i < 26; i++) {
		for(int j = 0; j < 7;j++)
			for (int k = 0; k < 5; k++) {
				cin >> alphas[i][j][k];
			}
	}
	getchar();
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (!(s[i] >= 'A' && s[i] <= 'Z'))
			s[i] = ' ';
	}
	
	bool is_first = true;
	stringstream ssin(s);
	
	while (ssin >> s) {
		if (is_first) is_first = false;
		else cout << endl;
		print(s);
	}
	
	return 0;
}
```

## 7-2 Block Reversing (25分)
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;
int e[N], ne[N];
int head, n, k;

vector<vector<int>> seq;

int main(void) {
	cin >> head >> n >> k;
	for (int i = 0; i < n; i++) {
		int addr, v, next;
		cin >> addr >> v >> next;
		e[addr] = v, ne[addr] = next;
	}
	vector<int> nodes;

	for (int i = head; i != -1; i = ne[i]) 
		nodes.push_back(i);
	
	for (int i = 0; i < nodes.size(); i += k) {
		vector<int> t;
		t.insert(t.begin(), nodes.begin() + i, nodes.begin() + min(i + k, (int)nodes.size()));
		seq.push_back(t);
	}

	nodes.clear();
	for (int i = seq.size() - 1; i >= 0; i--) {
		auto t = seq[i];
		for (auto e : t)
			nodes.push_back(e);
	}

	for (int i = 0; i < nodes.size(); i++) {
		if (i != nodes.size() - 1)
			printf("%05d %d %05d\n", nodes[i], e[nodes[i]], nodes[i + 1]);
		else
			printf("%05d %d -1\n", nodes[i], e[nodes[i]]);
	}

	return 0;
}
```

## 7-3 Summit (25分)
```c++
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 210;
bool st[N][N], tb[N];
int n, m, k;

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		st[a][b] = st[b][a] = true;
	}
	for (int i = 1; i <= n; i++)
		st[i][i] = true;
	cin >> k;
	for (int time = 1; time <= k; time++) {
		vector<int> people;
		memset(tb, 0, sizeof tb);
		int t;
		cin >> t;
		for (int i = 0; i < t; i++) {
			int v;
			cin >> v;
			people.push_back(v);
		}
		bool is_ok = true;
		for (int i = 0; i < people.size(); i++) {
			tb[people[i]] = true;
			for (int j = i + 1; j < people.size(); j++) {
				int m = people[i], n = people[j];
				if (!st[m][n])
					is_ok = false;
				tb[n] = true;
			}
		}
		if (!is_ok) printf("Area %d needs help.\n", time);
		else {
			bool is_perfect = true;
			for (int i = 1; i <= n; i++) {
				if (!tb[i]) {
					bool all_known = true;
					for (int j = 0; j < people.size(); j++) {
						int m = i, n = people[j];
						if (!st[m][n]) {
							all_known = false;
							break;
						}
					}
					if (all_known) {
						is_perfect = false;
						printf("Area %d may invite more people, such as %d.\n", time, i);
						break;
					}
				}
			}
			if (is_perfect)
				printf("Area %d is OK.\n", time);
		}
	}
	return 0;
}
```

## 7-4 Cartesian Tree (30分)
```c++
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 40;
int inorder[N], q[N];
unordered_map<int, int> l, r;
int n;

int build(int pl, int pr) {
	int k = pl, min_v = inorder[pl];
	for (int i = pl; i <= pr; i++) {
		if (inorder[i] < min_v) {
			k = i;
			min_v = inorder[i];
		}
	}
	int root = inorder[k];
	
	if (pl < k) l[root] = build(pl, k - 1);
	if (k < pr) r[root] = build(k + 1, pr);

	return root;
}

void bfs(int root) {
	int hh = 0, tt = 0;
	q[0] = root;

	while (hh <= tt) {
		if (l.count(q[hh])) q[++tt] = l[q[hh]];
		if (r.count(q[hh])) q[++tt] = r[q[hh]];
		hh++;
	}
}


int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> inorder[i];
	
	int root = build(0, n - 1);
	bfs(root);

	cout << q[0];
	for (int i = 1; i < n; i++)
		cout << " " << q[i];
	cout << endl;

	return 0;
}
```