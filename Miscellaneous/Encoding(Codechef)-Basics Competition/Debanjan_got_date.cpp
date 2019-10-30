/** Author : Vivek Bhardwaj
 * Problem available @ https://www.codechef.com/ENOC2019/problems/EN123
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k;
        int sum=0;
        while(n--){
            cin>>x;
            sum+=x;
        }
        if(k>=sum){
            cout<<"YES"<<"\n";
        }
        else cout<<"NO"<<"\n";
    }
    return 0;
}