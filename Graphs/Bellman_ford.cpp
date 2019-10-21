#include<bits/stdc++.h>
using namespace std;

const long long INF=1e18;

vector<long long> bellman_ford(vector<vector<pair<long long,long long>>> &v,int start){
    
    vector<long long> dist(v.size(),INF);
    dist[start]=0;
    vector<pair<long long,pair<long long,long long>>> edge_list;
    for(long long i=0;i<v.size();i++){
        for(auto j : v[i]){
            edge_list.emplace_back(i,j);
        }
    }

    for(long long it=0;it<v.size()-1;it++){
        for(auto i  : edge_list){
            if(dist[i.first]!=INF&&dist[i.second.first]>i.second.second+dist[i.first]){
                dist[i.second.first]=i.second.second+dist[i.first];
            }
        }
    }

    return dist;
}

int main(){

    long long n=5;
    vector<vector<pair<long long,long long>>> v(n);
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
    vector<long long> dist =bellman_ford(v,0);
    for(long long i=0;i<5;i++)
            cout<<dist[i]<<" ";

    return 0;
}