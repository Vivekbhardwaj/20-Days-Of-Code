/**Author : Vivek Bhardwaj
 * Dijkstra Implementation
 **/

#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;


/**Naive Approach of Djkstra O(n^2)
 * Suitable for Dense Graphs
 **/
/*vector<int> dijkstra(vector<vector<pair<int,int>>> v,int source){
    vector<int> distance(v.size(),INT_MAX);
    vector<bool> visited(v.size(),false);

    distance[source]=0;

    for(int it=0;it<v.size();it++){
        int min_distance=INT_MAX;
        int min_distance_unvisited_vertex=-1;

        for(int j=0;j<v.size();j++){
            if(distance[j]<min_distance&&(!visited[j])){
                min_distance=distance[j];
                min_distance_unvisited_vertex=j;
            }
        }
        visited[min_distance_unvisited_vertex]=true;

        for(auto i : v[min_distance_unvisited_vertex]){
            if(distance[i.first]==INT_MAX||distance[i.first]>distance[min_distance_unvisited_vertex]+i.second){
                distance[i.first]=distance[min_distance_unvisited_vertex]+i.second;
            }
        }
    }

    return distance;
}*/

/**Lazy Implementation of Djkstra using Set
 * O(nlogn)
 **/
vector<long long> dijkstra(vector<vector<pair<int,int>>> v,int source){
    vector<long long> distance(v.size(),INF);

    distance[source]=0;
    set<pair<long long,int>> s;
    s.insert({0,source});

    while(!s.empty()){
        for(auto i : v[s.begin()->second]){
            if(distance[i.first]==INF){
                distance[i.first]=distance[s.begin()->second]+i.second;
                s.emplace(distance[i.first],i.first);
            }
            else if(distance[i.first]>distance[s.begin()->second]+i.second){
                s.erase({distance[i.first],i.first});
                distance[i.first]=distance[s.begin()->second]+i.second;
                s.insert({distance[i.first],i.first});
            }
        }
        s.erase(s.begin());
    }

    return distance;
}

int main(){
    int n=5;
    vector<vector<pair<int,int>>> v(n);
    v[0].emplace_back(1,1);
    v[0].emplace_back(3,2);
    v[0].emplace_back(2,8);
    v[1].emplace_back(4,2);
    v[2].emplace_back(1,5);
    v[1].emplace_back(2,5);
    v[3].emplace_back(4,5);
    v[1].emplace_back(0,1);
    v[3].emplace_back(0,2);
    v[2].emplace_back(0,8);
    v[4].emplace_back(1,2);
    v[4].emplace_back(3,5);
    for(int i=0;i<5;i++){
        vector<long long> dist=dijkstra(v,i);
        for(auto i : dist){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
