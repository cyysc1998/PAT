#include <iostream>
#include <string>

using namespace std;
    
int n;
string s1, s2;

string conv(string s, int n) {
    int k = s.find('.');
    if (k == -1) s += ".", k = s.find('.');
    s = s.substr(0, k) + s.substr(k + 1);

    while (s.size() && s[0] == '0') s = s.substr(1), k--;
    if (s.empty()) k = 0; 
    if (s.size() > n) s = s.substr(0, n); 
    else s += string(n - s.size(), '0'); 
   
    return "0." + s + "*10^" + to_string(k);  
}

int main(void) {
    cin >> n >> s1 >> s2;
    string p = conv(s1, n), q = conv(s2, n);
    if (p == q)
        cout << "YES " << p << endl;
    else 
        cout << "NO " << p << " " << q << endl;
    return 0;
}

