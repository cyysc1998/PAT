#include<iostream>
#include<vector>
using namespace std;

class subtree {
public:
    vector<int> porder;
    vector<int> inorder;
    subtree(vector<int>& porder, vector<int>& inorder) {
        this->porder.assign(porder.begin(), porder.end());
        this->inorder.assign(inorder.begin(), inorder.end());
    }
};

int main(void) {
    int N;
    cin >> N;
    vector<int> porder(N), inorder(N);
    for(int i=0; i<N; i++) 
        cin >> porder[i];
    for(int i=0; i<N; i++)
        cin >> inorder[i];
    vector<int> res;
    vector<subtree> now, next;
    now.push_back(subtree(porder, inorder));

    while(!now.empty()) {
        for(auto t: now) {
            if(t.inorder.size() == 1) {
                res.push_back(t.inorder[0]);
                continue;
            }
            int root = t.porder.back();
            res.push_back(root);
            int index = 0;
            while(t.inorder[index] != root) index++;
            vector<int> left_p(t.porder.begin(), t.porder.begin()+index);
            vector<int> left_in(t.inorder.begin(), t.inorder.begin()+index);
            vector<int> right_p(t.porder.begin()+index, t.porder.end()-1);
            vector<int> right_in(t.inorder.begin()+index+1, t.inorder.end());
            if(index != 0) next.push_back(subtree(left_p, left_in));
            if(index != t.inorder.size()-1) next.push_back(subtree(right_p, right_in));
        }
        now.clear();
        now.assign(next.begin(), next.end());
        next.clear();
    }
    
    cout << res[0];
    if(res.size() > 1) {
        for(int i=1; i<res.size(); i++)
            cout << " " << res[i];
    }

}