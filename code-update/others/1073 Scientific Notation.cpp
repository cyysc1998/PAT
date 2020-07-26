#include <iostream>
#include <string>

using namespace std;

string s;

int main(void) {
    cin >> s;
    if (s[0] == '-') cout << "-";
    
    int k = s.find("E");
    string a = s[1] + s.substr(3, k - 3);
    int b = stoi(s.substr(k + 1));
    b++;
    
    if (b < 0) a = "0." + string(-b, '0') + a;
    else if (b > a.size()) a += string(b - a.size(), '0');
    else a = a.substr(0, b) + "." + a.substr(b);
    
    cout << a << endl;

    return 0;
}
