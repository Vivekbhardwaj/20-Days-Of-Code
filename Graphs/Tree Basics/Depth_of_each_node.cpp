#include<bits/stdc++.h>
using namespace std;


//preprocessing of depth of all nodes of the tree
void depth_of_tree(vector<vector<int>>&tree,vector<int>&depth,int current_node,int h){
    depth[current_node]=h;
    for(auto node : tree[current_node]){
        depth_of_tree(tree,depth,node,h+1);
    }       
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
    vector<int> depth(8);
    depth_of_tree(v,depth,0,0);
    for(auto i : depth) cout<<i<<" ";
}