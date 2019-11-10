/** Author : Vivekbhardwaj
 * Problem @ https://www.codechef.com/BCF12019/problems/CHFLOL2
 **/

#include<bits/stdc++.h>
using namespace std;

void dfs(long long source,vector<bool>&visited,vector<long long>&subtree,vector<vector<long long>>&adj){
    visited[source]=true;
    for(auto i : adj[source]){
        if(visited[i]) continue;
        dfs(i,visited,subtree,adj);
        subtree[source]+=subtree[i];
    }
    return;
}

int main(){
    long long t;cin>>t;
    while(t--){
        long long n,k,x,y,xh;cin>>n>>k>>xh;
        vector<vector<long long>> adj(n);
        vector<long long> value(n);
        for(auto &i: value) cin>>i;
        for(long long i=0;i<n-1;i++){
            cin>>x>>y;
            x--;y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> visited(n,false);
        dfs(0,visited,value,adj);
        vector<pair<long long,long long>> s(n);
        for(long long i=0;i<n;i++){
            s[i].first=value[i];
            s[i].second=i;
        }
        sort(s.begin(),s.end());
        fill(visited.begin(),visited.end(),false);
        long long ans=0;
        for(long long i=0;i<n&&k;i++){
                ans+=s[i].first;
                k--;
        }
        if(ans>=xh) cout<<0<<"\n";
        else cout<<xh-ans<<"\n";
    }
    return 0;
}