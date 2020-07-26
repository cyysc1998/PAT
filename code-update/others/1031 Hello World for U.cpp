#include<iostream>
#include<vector>
using namespace std;

const int N = 100;
char res[N][N];

int main(void) {
    string s;
    cin >> s;
    int N = s.size();
    int n1 = (N + 2)/3, n3 = (N + 2)/3;
    int n2 = N + 2 - 2*n1;

    int pos = 0;

    for(int i=0; i<n1; i++) 
        for(int j=0; j<n2; j++)
            res[i][j] = ' ';

    for(int i=0; i<n1; i++) res[i][0] = s[pos++];
    pos--;
    for(int i=0; i<n2; i++) res[n1-1][i] = s[pos++];
    pos--;
    for(int i=n1-1; i>=0; i--) res[i][n2-1] = s[pos++];

    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++)
            cout << res[i][j];
        cout << endl;
    }
}