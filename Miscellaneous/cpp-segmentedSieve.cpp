/**Author : Vivek Bhardwaj
 * Segmented Sieve
 * Finding Prime Numbers in in a range
 **/

#include<bits/stdc++.h>
using namespace std;

vector<long long> sieve_of_eratosthenes(int n){
    vector<long long> primes;
    vector<bool> isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;

    for(int i=2;i*i<=n+1;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n+1;j+=i) isPrime[j]=false;
        }
    }

    for(int i=0;i<n+1;i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

vector<long long> segmented_sieve(long long low,long long high){
    vector<long long> primes=sieve_of_eratosthenes(ceil(sqrt(high)));
    vector<long long> ans;
    long long isPrime[high-low+1];
    memset(isPrime,true,sizeof(isPrime));
    for(auto p : primes){
        for(int i=0;i<=high-low;i++){
            if(((i+low)%p)==0&&(i+low!=p)&&(i+low)!=1){
                isPrime[i]=false;
                for(;i<=high-low;i+=p) isPrime[i]=false;
            }
        }
    }

    for(int i=0;i<high-low+1;i++){
        if(isPrime[i]) ans.push_back(i+low);
    }

    return ans;
}


int main(){
    vector<long long> v=segmented_sieve(1427,14971);
    for(auto i : v) cout << i <<" ";
}
