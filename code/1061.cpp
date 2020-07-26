#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    map<char, string> hour{
        {'0', "00"}, {'1', "01"}, {'2', "02"}, {'3', "03"}, {'4', "04"}, {'5', "05"}, {'6', "06"}, {'7', "07"}, {'8', "08"}, {'9', "09"},
        {'A', "10"}, {'B', "11"}, {'C', "12"}, {'D', "13"}, {'E', "14"}, {'F', "15"}, {'G', "16"}, {'H', "17"}, {'I', "18"}, {'J', "19"},
        {'K', "20"}, {'L', "21"}, {'M', "22"}, {'N', "23"}
    };
    
    map<char, string> day{
        {'A', "MON"}, {'B', "TUE"}, {'C', "WED"}, {'D', "THU"}, {'E', "FRI"}, {'F', "SAT"}, {'G', "SUN"}
    };

    int t;

    int len = min(s1.size(), s2.size());

    for(t=0; t<len; t++) {
        if(s1[t] == s2[t] && s1[t] >= 'A' && s1[t] <= 'G') {
            cout << day[s1[t]] << " ";
            break;
        }
    }
    for(t++; t<len; t++) {
        if(s1[t] == s2[t] && (s1[t]>='A'&&s1[t]<='N' || s1[t]>='0'&&s1[t]<='9')) {
            cout << hour[s1[t]] << ":";
            break;
        }
    }

    int len_k = min(s3.size(), s4.size());

    for(t=0; t<len_k; t++) {
        if(s3[t] == s4[t] && (s3[t]>='a'&&s3[t]<='z'||s3[t]>='A'&&s3[t]<='Z')) {
            cout << setw(2) << setfill('0') << t << endl;
            break;
        }
    }

    return 0;
}