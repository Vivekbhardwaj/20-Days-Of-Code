#include<bits/stdc++.h>
using namespace std;

long long binaryExponentiation(long long base,long long exponent,long long MOD){
    long long res=1;
    base%=MOD;
    while(exponent!=0){
        //if exponent is odd do an extra step
        if(exponent&1) res=(res*base)%MOD;

        //divide the power by 2 and square the current value of base
        base=(base*base)%MOD;
        exponent>>=1;
    }

    return res;
}

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


/**a^Φ(n)=1(mod n)
 * multiplying by a^(-1) both sides
 * a^(-1)=a^(Φ(n)-1) (mod n)
 **/
long long inverseModulo(long long a,long long MOD){

    long long euler_totient=EulerTotient(MOD);
    return binaryExponentiation(a,euler_totient-1,MOD);
}




int main(){
    //if m is prime simply find binaryExponentiation(a,MOD-2,MOD)
}