/**Author : Vivek Bhardwaj
 * Problem @ https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/the-game-of-oxa/
 **/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n;cin>>n;
        vector<int> v(n);
        for(auto &i: v) cin>>i;
        int max_value=INT_MIN;
        for(int i=0;i<(1<<n);i++){
            vector<int> subset;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) subset.push_back(v[j]);
            }
            if((int)subset.size()==0)continue;
            //calculate the OXA value of this set
            int ans=subset[0];
            for(int i=1;i<(int)subset.size();i++){
                if(i%3==1) ans|=subset[i];
                else if(i%3==2) ans^=subset[i];
                else ans+=subset[i];
            }
            max_value=max(max_value,ans);
        }
        if(s=="Even"){
            if(max_value&1) cout<<"Mariam\n";
            else cout<<"Monk\n";
        }else{
            if(max_value&1) cout<<"Monk\n";
            else cout<<"Mariam\n";
        }
    }
    return 0;
}