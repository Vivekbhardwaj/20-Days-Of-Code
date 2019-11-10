/**Author : Vivek Bhardwaj
 *Problem @ https://www.codechef.com/DEFI2019/problems/GAOT
 **/

#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;
    int qu,x,y;cin>>qu;
    vector<vector<int>> v(n);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<bool>visited(n);
    vector<pair<int,int>>parent(n);
    for(auto &i : parent){
        i.first=-1;
        i.second=0;
    }
    parent[0].first=0;
    parent[0].second=1;
    queue<int> q;
    q.push(0); visited[0]=true;
            while(!q.empty()){             
                for(auto i : v[q.front()]){
                    if(!visited[i]){
                        parent[i].first=q.front();
                        visited[i]=true;
                        q.push(i);
                    }
                }
                q.pop();
            }


    while(qu--){
        cin>>x>>y;
        y--;
        if(x==1){
            parent[y].second=1;
            continue;
        }
        int count=0;
        while(parent[y].second!=1){
            y=parent[y].first;
            count++;
        }
        cout<<count<<"\n";
    }
    return 0;
}