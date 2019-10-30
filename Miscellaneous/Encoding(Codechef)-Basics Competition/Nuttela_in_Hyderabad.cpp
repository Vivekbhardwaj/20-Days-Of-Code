/** Author : Vivek Bhardwaj
 * Problem available @ https://www.codechef.com/ENOC2019/problems/ENOC2
**/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        if(a==b){
            cout<<"YES"<<"\n";continue;
        }
        else if(b<a){
            cout<<"NO"<<"\n";continue;
        }
        else if((a&1)&&(b&1)){
            cout<<"YES"<<"\n";continue;
        }
        else if((b%2==0)&&(a%2==0)){
            cout<<"YES"<<"\n";continue;
        }
        else if((2*a<=b)&&(b%2==0)){
            cout<<"YES"<<"\n";continue;
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}