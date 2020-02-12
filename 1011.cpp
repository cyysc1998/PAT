#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int main(void){
    double p[3];
    char s[3] = {'W','T','L'};
    double ans = 1;
    for(int i = 0; i < 3; i++){
        int m_index = 0;
        cin >> p[0] >> p[1] >> p[2];
        if(p[1] > p[m_index])
            m_index = 1;
        if(p[2] > p[m_index])
            m_index = 2;
        cout << s[m_index] << " ";
        ans *= p[m_index];
    }
    cout << fixed << setprecision(2) << (ans * 0.65 - 1)*2;
}