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

/**A prime number must follow
 * (a^(p-1)-1)%p==0 i.e fermats little theorm
 **/
bool isPrime(long long check,int iter=5){

    if (check < 4)
        return check == 2 || check == 3;

    /**Picking base for some arbitary no of iterations,
     * and checking everytime
     * Greater the number of iterations more precise the algorithm is.
     * i.e lesser chances of error
     **/
    for(int i=0;i<iter;i++){

        //avoiding 0 and 1 as base that is why minimum of 2 is chosen
        long long a=2+rand()%(check-3);
        if(binaryExponentiation(a,check-1,check)!=1) return false;
    }
    return true;
}


int main(){
    cout<<isPrime(47)<<endl;
}