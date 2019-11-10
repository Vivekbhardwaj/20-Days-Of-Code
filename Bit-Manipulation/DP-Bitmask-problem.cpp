/**Author : Vivek Bhardwaj
 * Problem @ https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/monks-visit-to-amathville/
 * DP with Bitmasking with a slight taste of number theory
 **/

#include<bits/stdc++.h>
using namespace std;

long long dp[400000][20];

int p;
vector<int> primes;

long long solve(int mask,int prev){
    if(mask+1==(1<<(int)primes.size())) return 0;
    if(dp[mask][prev]!=-1) return dp[mask][prev];

    long long res=INT_MAX;
    for(int i=0;i<(int)primes.size();i++){
        if(mask&(1<<i)) continue;
        res= min(res,(primes[i]*primes[prev])%p+solve(mask|(1<<i),i));
    }
    return dp[mask][prev]=res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n>>p;

        //sieve
        vector<int> v(n+1,1);
        for(int i=2;i<n+1;i++){
            if(v[i]==0)continue;
            for(int j=i+i;j<n+1;j+=i) v[j]=0;
        }

        //vectors of primes upto n
        for(int i=1;i<n+1;i++){
            if(v[i]==1)primes.push_back(i);
        }
        long long res=INT_MAX;

        //creating arrangements of primes
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<(int)primes.size();i++){
            int mask=0|(1<<i);
            res = min(res,solve(mask,i));
        }
        cout<<res<<"\n";
        primes.clear();
    }
    return 0;
}