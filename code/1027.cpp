#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

string cev(int N) {
    vector<string> table  = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C"};
    string res;
    if(N == 0)
        return to_string(0);
    while(N != 0) {
        res = table[N%13] + res;
        N = N/13;
    }
    return res;
}

int main(void) {
    int R, G, B;
    cin >> R >> G >> B;
    cout << "#";
    cout << setw(2) << setfill('0') << cev(R);
    cout << setw(2) << setfill('0') << cev(G);
    cout << setw(2) << setfill('0') << cev(B);
} 