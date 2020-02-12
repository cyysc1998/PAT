#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int N;
    vector<int> sequence;
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        sequence.push_back(temp);
    }

    int maxSum = -1;
    int tempSum = 0;
    int begin = 0, end = sequence.size()-1, last_index = 0;
    for(int i=0; i<sequence.size(); i++){
        tempSum += sequence.at(i);
        if(maxSum < tempSum){
            maxSum = tempSum;  
            begin = last_index;
            end = i;
        }
        else if(tempSum < 0){
            tempSum = 0;
            last_index = i+1;
        }
    }
    maxSum = max(maxSum,0);
    cout << maxSum << " " <<sequence.at(begin) << " " << sequence.at(end) << endl;
}