/** Author : Vivek Bhardwaj
 * Problem available @ https://www.codechef.com/ENOC2019/problems/ENOC4/
**/

#include <iostream>
using namespace std;


const long long MOD=1000000007;

int main() {
    
    long long n,k;
    int t;
    cin>>t;
    while(t--){
        long long sum=0;
        cin>>n>>k;
        long long x=n/k;
        sum=((x%MOD)*((x+1)%MOD))%MOD;
        sum=(sum*k)%MOD;
            sum=(sum+(n)%MOD)%MOD;
            cout<<sum<<"\n";
    }
    
	return 0;
}