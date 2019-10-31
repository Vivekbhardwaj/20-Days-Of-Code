#include<bits/stdc++.h>
using namespace std;

int height_of_node(vector<vector<int>>&tree,int node,vector<int>&height){
    if((int)tree[node].size()==0) return 0;
    int max_height=INT_MIN;
    for(auto i : tree[node]){
        max_height= max(height_of_node(tree,i,height),max_height);
    }
    return height[node]=max_height+1;
}


int main(){
    vector<vector<int>>v(8);
    v[0].push_back(1);
    v[0].push_back(2);
    v[0].push_back(3);
    v[1].push_back(4);
    v[1].push_back(5);
    v[2].push_back(6);
    v[6].push_back(7);
    vector<int> height(8);
    height_of_node(v,0,height);
    for(auto i : height) cout<<i<<" ";
}