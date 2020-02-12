// Spell It Right

#include<cstdio>
#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int main(void){
    string number;
    vector<int> digit;
    int sum = 0;
    cin >> number;
    
    string symbol[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int i=0; i<number.length(); i++){
       sum += (number.at(i) - '0');
    }

    stringstream ss;
    ss << sum;
    
    string ans = ss.str();
    for(int i=0; i<ans.length()-1; i++){
        cout << symbol[ans.at(i)-'0'] << " ";
    }
    cout << symbol[ans.at(ans.length()-1)-'0'];
}