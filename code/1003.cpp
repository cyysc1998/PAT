// Emergency

#include<cstdio>
#include<climits>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class road{
    public:
    int destination;
    int distance;
    road(int dest=0, int dis=INT_MAX){
        destination = dest;
        distance = dis;
    }
};

class node{
    public:
    int recsue;
    int maxRescue;
    int minLength;
    bool known;
    vector<road> neighbor;
    int times;
    node(){}
    node(int rec){
        recsue = rec;
        minLength = INT_MAX;
        maxRescue = 0;
        known = false;
        times = 0;
    }
};

int main(void){
    int N, M ,start, end;
    vector<node> city;
    int recsue;
    int road_start, road_end, road_length;
    cin >> N >> M >> start >> end;
    for(int i=0; i<N; i++){
        cin >> recsue;
        city.push_back(node(recsue));
    }
    for(int i=0; i<M; i++){
        cin >> road_start >> road_end >> road_length;
        city.at(road_start).neighbor.push_back(road(road_end, road_length));
        city.at(road_end).neighbor.push_back(road(road_start, road_length));
    }

    city.at(start).known = true;
    city.at(start).minLength = 0;
    city.at(start).maxRescue = city.at(start).recsue;
    city.at(start).times = 1;

    vector<road>:: iterator it_neighbor;
    for(it_neighbor = city.at(start).neighbor.begin(); it_neighbor != city.at(start).neighbor.end(); it_neighbor++){
        city.at((*it_neighbor).destination).minLength = (*it_neighbor).distance;
        city.at((*it_neighbor).destination).maxRescue = city.at(start).maxRescue + city.at((*it_neighbor).destination).recsue;
        city.at((*it_neighbor).destination).times = 1;
    }

    int know_number = 1;

    while(know_number < N){
        
        int index = 0;
        int short_dis = INT_MAX;
        for(int i=0; i<city.size(); i++){
            if(city[i].minLength < short_dis && city[i].known==false){
                index = i;
                short_dis = city[i].minLength;
            }
        }
        
        node& minNode = city[index];
        minNode.known = true;

        vector<road> neighbors = minNode.neighbor;
        vector<road>:: iterator it_neighbor;

        for(it_neighbor = neighbors.begin(); it_neighbor!= neighbors.end(); it_neighbor++){
            
            if(city.at((*it_neighbor).destination).minLength > minNode.minLength + (*it_neighbor).distance  \
              && city.at((*it_neighbor).destination).known==false){

                city.at((*it_neighbor).destination).minLength = minNode.minLength + (*it_neighbor).distance;
                city.at((*it_neighbor).destination).times = minNode.times;
                city.at((*it_neighbor).destination).maxRescue = minNode.maxRescue + city.at((*it_neighbor).destination).recsue;

            }

            else if(city.at((*it_neighbor).destination).minLength == minNode.minLength + (*it_neighbor).distance  \
              && city.at((*it_neighbor).destination).known==false){
                city.at((*it_neighbor).destination).times += minNode.times;
                city.at((*it_neighbor).destination).maxRescue = max(minNode.maxRescue + city.at((*it_neighbor).destination).recsue, \
                    city.at((*it_neighbor).destination).maxRescue);
            }
        }
        know_number++;
    }
    cout << city.at(end).times << " " << city.at(end).maxRescue << endl;

    return 0;
}



