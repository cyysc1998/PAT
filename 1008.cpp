#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int N;
    vector<int> layer;
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        layer.push_back(temp);
    }
    int cur_layer = 0;
    int sum = 0;
    for(int i = 0; i < layer.size(); i++){
        if(layer[i] > cur_layer)
            sum += (layer[i] - cur_layer)*6;
        else if(layer[i] < cur_layer)
            sum += (cur_layer - layer[i])*4;
        sum += 5;
        cur_layer = layer[i];
    }
    cout << sum;
}