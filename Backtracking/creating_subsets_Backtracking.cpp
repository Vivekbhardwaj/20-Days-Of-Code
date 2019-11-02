/**Author : Vivek Bhardwaj
 * Creating Subsets using Recursion and Backtracking
 **/


#include<bits/stdc++.h>
using namespace std;

int v[1005];

void subsets(int i,int n,vector<int> &x){
    for(int j=i+1;j<n;j++){
        x.push_back(v[j]);

        cout<<"{";
        for(auto it : x) cout<<it<<",";
        cout<<"}\n";
      
        subsets(j,n,x);     //Recursion Step;
        x.pop_back();       //Backtracking Step;
    }
}


int main(){
    int n;cin>>n;
    iota(v,v+n,1);
    vector<int> x;
    subsets(-1,n,x);
}