//Counting Leaves

#include<cstdio>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class layer{
public:
    int leaf;
    vector<int> children;
    layer(){leaf=0;}
};

int main(void){
    map<int, vector<int> > nodes;
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        vector<int> temp;
        int temp_root, child_num, temp_child;
        cin >> temp_root >> child_num;
        for(int j=0; j<child_num; j++){
            cin >> temp_child;
            temp.push_back(temp_child);
        }
        nodes[temp_root] = temp;
    }

    vector<int> ans;
    vector<int> cur_layer, next_layer;
    if(nodes[1].size() != 0){
        for(int i=0; i<nodes[1].size(); i++){
            cur_layer.push_back(nodes[1].at(i));
        }
        ans.push_back(0);
    }
    else
        ans.push_back(1);
    
    while(!cur_layer.empty()){
        vector<int>::iterator it;
        int leaves = 0;
        map<int, vector<int> >:: iterator iter;
        for(it = cur_layer.begin(); it != cur_layer.end(); it++){
            iter = nodes.find(*it);
            if(iter != nodes.end()){
                vector<int>::iterator iter_child;
                for(iter_child = nodes[*it].begin(); iter_child != nodes[*it].end(); iter_child++){
                    next_layer.push_back(*iter_child);
                }
            }
            else
                leaves++;
        }
        ans.push_back(leaves);
        cur_layer = next_layer;
        next_layer.clear();
    }

    vector<int>::iterator iter;
    for(iter = ans.begin(); iter != ans.end()-1; iter++){
        cout << *iter << " ";
    }
    cout << *(ans.end()-1);
    
}