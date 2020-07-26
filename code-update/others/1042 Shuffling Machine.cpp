#include <iostream>
#include <vector>

using namespace std;

const int N = 60;
int trans[N];
vector<string> p;
int k;

void conv(void) {
    vector<string> t = p;
    for(int i = 0; i < 54; i ++) 
        p[trans[i] - 1] = t[i];
}

int main(void) {
    cin >> k;
    for(int i = 0; i < 54; i++)
        cin >> trans[i];
    for(int i = 1; i <= 13; i ++)
        p.push_back("S" + to_string(i));
    for(int i = 1; i <= 13; i ++)
        p.push_back("H" + to_string(i));
    for(int i = 1; i <= 13; i ++)
        p.push_back("C" + to_string(i));
    for(int i = 1; i <= 13; i ++)
        p.push_back("D" + to_string(i));
    p.push_back("J1");
    p.push_back("J2");
   
    for(int i = 0; i < k; i ++)
        conv();
    
    cout << p[0];
    for(int i = 1; i < 54; i ++)
        cout << " " << p[i];
    cout << endl;

    return 0;
}