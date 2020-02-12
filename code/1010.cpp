#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long ull;

ull parse(string N, int radix){
    ull sum = 0;
    int size = N.length();
    for(int i=0; i<size; i++){
        if(N.at(i) >= '0' && N.at(i) <= '9'){
            sum += pow(radix, size-i-1)*(N.at(i)-'0');
        }
        else if(N.at(i) >= 'a' && N.at(i) <= 'z'){
            sum += pow(radix, size-i-1)*(N.at(i)-'a' + 10);
        }
    }
    return sum;
}

ull find(ull begin, ull end, string N, ull ans){
    while(begin <= end){
        ull p = (begin+end)/2;
        ull ans_2 = parse(N, p);
        if(ans == ans_2)
            return p;
        else if(ans_2 > ans || ans_2 < 0)
            end = p - 1;
        else
            begin = p + 1;
    }
    return -1;
}

int main(void){
    string N1, N2;
    ull tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    if(tag == 2){ string tmp = N1; N1 = N2; N2 = tmp; }
    
    ull ans_1 = parse(N1, radix);

    ull min = 2;
    for(int i=0 ; i<N2.size(); i++){
        if(N2.at(i)>='0' && N2.at(i)<='9'){
            if(min < N2.at(i)-'0')
                min = N2.at(i)-'0'+1;
        }
        else{
            if(min < N2.at(i)-'a'+10)
                min = N2.at(i)-'a' + 10+1;
        }
    }
    ull max = 2;
    while(parse(N2, max) < ans_1)
        max *= 2;
    if(max < min)
        max = min;
    
    ull radix_2 = find(min, max, N2, ans_1);
    if(radix_2 == -1)
        cout << "Impossible";
    else
        cout << radix_2;
}