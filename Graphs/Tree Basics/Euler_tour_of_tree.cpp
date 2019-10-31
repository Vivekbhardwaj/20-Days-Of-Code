#include<bits/stdc++.h>
using namespace std;

void height_of_tree(vector<vector<int>>&tree,vector<int>&euler,int current_node){
    euler.push_back(current_node);
    for(auto nodes : tree[current_node]){
        height_of_tree(tree,euler,nodes);

        euler.push_back(current_node);
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
    vector<int> euler;
    height_of_tree(v,euler,0);
    for(auto i : euler) cout<<i<<" ";
}