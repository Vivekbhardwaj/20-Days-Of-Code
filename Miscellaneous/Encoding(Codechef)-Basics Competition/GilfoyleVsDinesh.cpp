/** Author : Vivek Bhardwaj
 * Problem available @ https://www.codechef.com/ENOC2019/problems/GVR
**/

#include <iostream>
#include<vector>
using namespace std;


long long binpower(long long base, long long e, long long mod) {
    long long result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        e >>= 1;
    }
    return result;
}


/**A prime number must follow
 * (a^(p-1)-1)%p==0 i.e fermats little theorm
 **/
bool probablyPrimeFermat(int n, int iter=5) {
    if (n < 4)
        return n == 2 || n == 3;

    /**Picking base for some arbitary no of iterations,
     * Greater the number more precise the algorithm is.
     * i.e lesser chances of error
     **/
    for (int i = 0; i < iter; i++) {
        //Picking up a random base a
        int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

int main() {
	int n;cin>>n;
    vector<long long> v(n);
    for(auto &i : v)cin>>i;
    bool firstprime=false,lastprime=false;
    int count1=0;
    int count2=0;
    long long fir,las;
    for(int i=0;i<n/2;i++){
        if(probablyPrimeFermat(v[i])){
            count1++;
            if(!firstprime){firstprime=true;fir=v[i];}
        }     
    }
    for(int i=n-1;i>=n/2;i--){
        if(probablyPrimeFermat(v[i])){
            count2++;
            if(!lastprime){las=v[i];lastprime=true;}
        }     
    }

    if(count1==count2){
        if(fir>las){
            cout<<"PERFECT\n";
            return 0;
        }
    }
    cout<<"IMPERFECT\n";
	return 0;
}