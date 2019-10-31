#include<bits/stdc++.h>
using namespace std;


//Φ(n)=n*(1-1/p1)*(1-1/p2)*(1-1/p3)*...................(1-1/p(n'th))
long long EulerTotient(long long n){
    double ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            ans*=1-(1.0)/i;
        }
    }

    //if(n>1) it means it has a prime factor greater than sqrt(n) and it is n
    //there can only be one such prime factor
    if(n>1) ans*=1-(1.0)/n;

    return (long long)ans;
}


int main(){
    cout<<EulerTotient(8)<<"\n";
}




/**Another method to avoid floating point
 long long EulerTotient(long long n){
    long long ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            ans-=ans/i;
        }
    }

    if(n>1) ans-=ans/n;

    return ans;
}
**/