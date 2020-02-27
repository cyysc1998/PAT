#include<bits/stdc++.h>
using namespace std;

string card(int n) {
    if(n>=1 && n<=13)
        return "S" + to_string(n);
    else if(n>=14 && n<=26)
        return "H" + to_string(n-13);
    else if(n>=27 && n<=39)
        return "C" + to_string(n-26);
    else if(n>=40 && n<=52)
        return "D" + to_string(n-39);
    else
        return "J" + to_string(n-52);
}

void trans(vector<string>& c, vector<int>& order) {
    vector<string> t(55);
    for(int i=1; i<=54; i++) 
        t[order[i]] = c[i];
    c = t;
}

int main(void) {
    vector<int> order(55);
    vector<string> c(55);
    int K;
    cin >> K;
    for(int i=1; i<=54; i++)
        c[i] = card(i);
    for(int i=1; i<=54; i++)
        cin >> order[i];
    for(int i=0; i<K; i++)
        trans(c, order);
    cout << c[1];
    for(int i=2; i<=54; i++)
        cout << " " << c[i];
    return 0;
}