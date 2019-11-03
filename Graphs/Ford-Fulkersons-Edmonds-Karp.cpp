#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> g,int source,int sink,vector<int>&parent,vector<vector<int>> &residual_capacity){
    int path_max_flow=INT_MAX;
    vector<bool> visited((int)g.size());
    fill(parent.begin(),parent.end(),-1);
    queue<int> q;q.push(source);visited[source]=true;
    while(!q.empty()){
        int curr=q.front();q.pop();
        if(curr==sink) return path_max_flow;
        for(auto i : g[curr]){
            //we only consider the node which is not visited and the edge to which has non zero residual capacity
            if(!visited[i]&&residual_capacity[curr][i]>0){
                visited[i]=true;
                path_max_flow=min(path_max_flow,residual_capacity[curr][i]);
                parent[i]=curr;
                q.push(i);
            }
        }
    }
    return 0;       //returns zero if no path is found which reaches the sink
}


int fordFulkersons(vector<vector<int>> g,int source,int sink,vector<vector<int>>capacity){

    //Adding reversed edges to the graph with 0  capacity
    for(int i=0;i<(int)g.size();i++){
        for(auto j : g[i]){
            if(find(g[j].begin(),g[j].end(),i)==g[j].end()){
                g[j].push_back(i);
            }
        }
    }

    int max_flow=0;
    int path_flow;
    vector<int>parent(g.size());

    //loop continues till no argumented path with positive path flow is found
    while(path_flow=bfs(g,source,sink,parent,capacity)){
        int prev=parent[sink];
        int curr=sink;


        vector<int> print_path;     //utility for visualization of the path

        //updating the residual capacities along the path which reached the sink(tracing back the path)
        while(prev!=-1){
            print_path.push_back(prev);
            capacity[prev][curr]-=path_flow;        //residual capacity fo the edge in direction decreases by the amount of path flow which is pushed through it
            capacity[curr][prev]+=path_flow;        //residual capacity fo the edge in reverse direction increases by the amount of path flow which is pushed opposite to it
            curr=prev;
            prev=parent[prev];
        }
        reverse(print_path.begin(),print_path.end());
        
        //---------------------------------------------------------------------------------------
        //printing the argumented path and maximum amount of flow that can be pushed through it
        for(auto i : print_path) cout<<i<<"->";cout<<sink<<"(sink)"<<"\n";
        cout<<"flow that can be pushed through this path "<<path_flow<<endl;
        //-----------------------------------------------------------------------------------------

        max_flow+=path_flow;
    }
    return max_flow;
}

int main(){
    vector<vector<int>>v(6);
    v[0].push_back(1);
    v[0].push_back(2);
    v[1].push_back(2);
    v[1].push_back(3);
    v[2].push_back(1);
    v[2].push_back(4);
    v[3].push_back(2);
    v[3].push_back(5);
    v[4].push_back(3);
    v[4].push_back(5);
    vector<vector<int>> capacity =    { {0, 16, 13, 0, 0, 0}, 
                                        {0, 0, 10, 12, 0, 0}, 
                                        {0, 4, 0, 0, 14, 0}, 
                                        {0, 0, 9, 0, 0, 20}, 
                                        {0, 0, 0, 7, 0, 4}, 
                                        {0, 0, 0, 0, 0, 0} }; 
    
    
    int max_flow_through_graph=fordFulkersons(v,0,5,capacity);

    cout<<"Max-flow through the graph is "<<max_flow_through_graph<<"\n";
}