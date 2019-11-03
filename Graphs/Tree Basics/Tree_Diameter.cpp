#include<bits/stdc++.h>
using namespace std;

/**Diameter finding includes a slight modification in general DFS
 * it involves doing 2 DFS one after the other
 * first dfs is done from any arbitary node (usually node 0 for simplicity)
 * then the node furthest from the root(considerd or given) is found
 * second dfs is done from the node thus found
 * and now the distance of maximum distant node is found and it is the diameter
 **/
void dfs(vector<vector<int>> g,vector<bool>&visited,int start,pair<int,int>&max_distant_node,int curr_distance=0){

    visited[start]=true;

    if(max_distant_node.first<curr_distance){
       max_distant_node.first=curr_distance;
       max_distant_node.second=start;
    }
    for(auto i : g[start]){
        if(!visited[i]){
            dfs(g,visited,i,max_distant_node,curr_distance+1);
        }
    }
}

int main(){

    //Store the tree as an undirected graph
    vector<vector<int>> v(10);
    v[0].push_back(1);v[1].push_back(0);
    v[1].push_back(2);v[2].push_back(1);
    v[2].push_back(3);v[3].push_back(2);
    v[0].push_back(4);v[4].push_back(0);
    v[0].push_back(5);v[5].push_back(0);
    v[5].push_back(6);v[6].push_back(5);
    v[5].push_back(7);v[7].push_back(5);
    v[7].push_back(8);v[8].push_back(7);

    vector<bool> visited((int)v.size(),false);
    pair<int,int>max_distant={0,0};
    
    dfs(v,visited,0,max_distant);                                   //first dfs to find max_distant node from the root node
    
    int beg=max_distant.second;
    max_distant.first=0;

    fill(visited.begin(),visited.end(),false);                      //reset the visited vector to all false
    
    dfs(v,visited,beg,max_distant);
   
    cout<<"Diameter of the tree is (Distance between nodes "<<beg<<"<-->"<<max_distant.second<<")="<<max_distant.first<<"\n";
    return 0;
}