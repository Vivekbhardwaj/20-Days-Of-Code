/**Author : Vivek Bhardwaj
 * Question available at the link below : 
 * https://www.hackerrank.com/challenges/even-tree/problem
 **/

#include <bits/stdc++.h>

using namespace std;

void dfs(long long start,vector<bool>&visited,vector<vector<long long>> &v,vector<long long>&nodes_in_subtree){
    if(v[start].size()==0) return;
    for(auto i : v[start]){
        if(!visited[i]){
            visited[i]=true;
           dfs(i,visited,v,nodes_in_subtree);
           nodes_in_subtree[start]+=nodes_in_subtree[i];
        }
    }
    return;
}

int main()
{
    
    long long n,m,x,y;
    cin>>n>>m;
    vector<vector<long long>> v(n);
    long long start=0;
    vector<long long> nodes_in_subtree(n,1);
    vector<bool> visited(n,false);
    visited[start]=true;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(start,visited,v,nodes_in_subtree);
    long long res=0;
    for(auto i : nodes_in_subtree){
        
        if(i&1){

        }
        else res++;
    }
    

    cout << res-1 << "\n";

   

    return 0;
}

