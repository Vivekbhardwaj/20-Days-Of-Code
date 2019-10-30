/** Author : Vivek Bhardwaj
 * Problem available @ https://www.codechef.com/ENOC2019/problems/ENOC3/
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
        //sometimes its better to take input as string ,even if the no. fits in the range of long long 
	    string s;cin>>s;
	    if((int)s.size()==1){
	        cout<<s<<"\n";
	        continue;
	    }
	    for(int i=0;i<(int)s.size()-1;i++){
	        int x=s[i]-48;
	        int y=s[i+1]-48;
	        int z=x^y;
	        cout<<z;
	    }
	    int x=s[(int)s.size()-1]-48;
	    int y=s[0]-48;
	    int z=x^y;
	    cout<<z<<"\n";
	}
	return 0;
}