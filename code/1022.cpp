#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

void query(map<string, vector<string>>& m, string& content) {
    map<string, vector<string>>::iterator it;
    if((it = m.find(content))!= m.end()) {
        for(auto e: it->second)
            cout << e << endl;
    }
    else
        cout << "Not Found" << endl;
}

int main(void) {
    map<string, vector<string>> title, author, key, publisher, year;
    int N;
    string temp;
    getline(cin, temp);
    N = stoi(temp);
    for(int i = 0; i < N; i++) {
        string t_ID,t_title, t_author, t_key, t_publisher, t_year;
        vector<string> v_key;

        getline(cin, t_ID);
        getline(cin, t_title);
        title[t_title].push_back(t_ID);
        getline(cin, t_author);
        author[t_author].push_back(t_ID);
        string part;
        while(cin >> part) {
            key[part].push_back(t_ID);
            char c = getchar();
            if(c == '\n') break;
        }
        getline(cin, t_publisher);
        publisher[t_publisher].push_back(t_ID);
        getline(cin, t_year);
        year[t_year].push_back(t_ID);
    }

    map<string, vector<string>>::iterator it;
    for(it = title.begin(); it != title.end(); it++)
        sort(it->second.begin(), it->second.end());
    for(it = author.begin(); it != author.end(); it++)
        sort(it->second.begin(), it->second.end());
    for(it = key.begin(); it != key.end(); it++)
        sort(it->second.begin(), it->second.end());
    for(it = publisher.begin(); it != publisher.end(); it++)
        sort(it->second.begin(), it->second.end());
    for(it = year.begin(); it != year.end(); it++)  
        sort(it->second.begin(), it->second.end());

    int M;
    getline(cin, temp);
    M = stoi(temp);
    for(int i=0; i<M; i++) {
        string q;
        getline(cin, q);
        cout << q << endl;
        int type = stoi(q.substr(0,1));
        string content = q.substr(3);
       
        if(type == 1) query(title, content);
        else if(type == 2) query(author, content);
        else if(type == 3) query(key, content);
        else if(type == 4) query(publisher, content);
        else if(type == 5) query(year, content);
    }
}