/** Author : Vivek Bhardwaj
 * Problem available @ https://www.codechef.com/ENOC2019/problems/SS4
**/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,x,y;cin>>n;
    vector<bool>visited(n,false);
    vector<vector<int>>v(n);
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    vector<int> level(n);
    level[0]=1;
    int current_level=1;
    int ans=1;
    int sum=0;
    int max_level=1;
    
    queue<int> q; q.push(0); visited[0]=true;
            while(!q.empty()){

                //whenever level of search changes sum is initialized to zero 
                if(current_level!=level[q.front()]){
                    current_level=level[q.front()];
                    sum=0;
                }
                for(auto i : v[q.front()]){
                    if(!visited[i]){
                        sum++;
                        visited[i]=true;
                        level[i]=level[q.front()]+1;
                        q.push(i);
                        
                        //whenever the sum in current level increases above max level ans,update the max_level to current level
                        if(ans<sum){
                            max_level=level[i];
                            ans=sum;
                        }
                        
                    }
                }
                q.pop();
            }
            cout<<max_level<<"\n";
    
    return 0;
}
