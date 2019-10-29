/**Author : Vivek Bhardwaj
 * Sieve Of Eratosthenes
 * Finding Prime Numbers in O(Nlog(lonN))
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


int main(){
    vector<long long> v=sieve_of_eratosthenes(100);
    for(auto i : v) cout << i <<" ";
}
