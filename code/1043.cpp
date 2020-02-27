#include<bits/stdc++.h>
using namespace std;

class tree {
public:
    tree* left;
    tree* right;
    int v;
    tree(tree* left, tree* right, int v): left(left), right(right), v(v) {}
};

void insert(tree* &t, int v) {
    if(t == NULL) { 
        t = new tree(NULL, NULL, v);
        return;
    }
    if(t->v > v)
        return insert(t->left, v);
    else if(t->v <= v)
        return insert(t->right, v);
}

void preorder(tree* T, vector<int>& s) {
    if(T == NULL)
        return;
    s.push_back(T->v);
    preorder(T->left, s);
    preorder(T->right, s);
}

void preorder_m(tree* T, vector<int>& s) {
    if(T == NULL)
        return;
    s.push_back(T->v);
    preorder_m(T->right, s);
    preorder_m(T->left, s);
}

void postorder(tree* T, vector<int>& s) {
    if(T == NULL)
        return;
    postorder(T->left, s);
    postorder(T->right, s);
    s.push_back(T->v);
}

void postorder_m(tree* T, vector<int>& s) {
    if(T == NULL)
        return;
    postorder_m(T->right, s);
    postorder_m(T->left, s);
    s.push_back(T->v);
}

int main(void) {
    int N;
    cin >> N;
    vector<int> origin(N);
    tree* T = NULL;
    for(int i=0; i<N; i++) {
        cin >> origin[i];
        insert(T, origin[i]);
        
    }
    vector<int> s, s_m;
    preorder(T, s);
    preorder_m(T, s_m);
    
    if(s == origin) { 
        s.clear();
        postorder(T, s);
        cout << "YES" << endl;
        cout << s[0];
        for(int i=1; i<N; i++)
            cout << " " << s[i];
    }
    else if(s_m == origin) {
        s_m.clear();
        postorder_m(T, s_m);
        cout << "YES" << endl;
        cout << s_m[0];
        for(int i=1; i<N; i++)
            cout << " " << s_m[i];
    }
    else
        cout << "NO" << endl;
    return 0;
}


