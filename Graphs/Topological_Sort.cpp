/**Author : Vivek Bhardwaj
 * Topological Sorting of A DAG
 **/

#include<bits/stdc++.h>
using namespace std;

void topological_sort(vector<vector<int>> &v,vector<int>&ans,vector<bool>&visited,int start=0){
    visited[start]=true;
    for(auto i  : v[start]){
        if(!visited[i]) topological_sort(v,ans,visited,i);
    }
    ans.push_back(start);
}

int main(){

    vector<vector<int>>g(5);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(4);
    g[1].push_back(3);
    g[2].push_back(3);
    g[4].push_back(2);
    g[3].push_back(4);

    vector<int> ans;
    vector<bool> visited(5,false);
    topological_sort(g,ans,visited);
    reverse(ans.begin(),ans.end());
    for(auto i : ans) cout<<i<<" ";
}