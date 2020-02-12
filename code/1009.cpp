#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

int main(void){
    map<int,double,greater<int> > a, b, c;
    int K, tmp_exp; 
    double tmp_coe;
    cin >> K;
    for(int i=0; i < K; i++){
        cin >> tmp_exp >> tmp_coe;
        a.insert(map<int,double>::value_type (tmp_exp, tmp_coe));
    }
    cin >> K;
    for(int i=0; i < K; i++){
        cin >> tmp_exp >> tmp_coe;
        b.insert(map<int,double>::value_type (tmp_exp, tmp_coe));
    }
    map<int, double>:: iterator a_l = a.begin(), b_l, c_l;
    while(a_l != a.end()){
        b_l = b.begin();
        while(b_l != b.end()){
            int n_exp = a_l->first + b_l->first;
            double n_coe = a_l->second * b_l->second; 
            if(c.find(n_exp) == c.end())
                c.insert(map<int, double>:: value_type(n_exp, n_coe));
            else
                c[n_exp] += n_coe;
            b_l++;
        }
        a_l++;
    }

    c_l = c.begin();
    while(c_l != c.end()){
        if(c_l->second == 0)
            c.erase(c_l++);
        else
            c_l++;
    }
    cout << c.size();
    
    c_l = c.begin();
    while(c_l != c.end()){
        cout << " " << c_l->first << " " << fixed << setprecision(1) << c_l->second;
        c_l++;
    }
}