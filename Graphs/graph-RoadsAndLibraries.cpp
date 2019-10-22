/**Author : Vivek Bhardwaj
 * Question available at the link below : 
 * @https://www.hackerrank.com/challenges/torque-and-development/problem
 **/

#include <bits/stdc++.h>

using namespace std;


long long roadsAndLibraries(long long n, long long c_lib, long long c_road, vector<vector<long long>> cities) {
    long ans=0;
    if(c_lib<c_road) {ans=n*c_lib; return ans;} 
    vector<vector<long long>> g(n);
    
    for(long long i=0;i<cities.size();i++){
        g[--cities[i][0]].push_back(--cities[i][1]);
        g[cities[i][1]].push_back(cities[i][0]);
    }

    vector<bool> visited(n,false);
    for(long long i=0;i<n;i++){
        if(visited[i]) continue;
        ans+=(c_lib);
        long long count=0;
        queue<long long> q;
        q.push(i);
        visited[i]=true;
        while(!q.empty()){
            for(auto it : g[q.front()]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push(it);
                    count++;
                }
            }
            q.pop();
        }
        ans+=(count*c_road);
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long long q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (long long q_itr = 0; q_itr < q; q_itr++) {

        long long n;
        long long m;
        long long c_lib;
        long long c_road;

        cin>>n>>m>>c_lib>>c_road;
        vector<vector<long long>> cities(m);
        for (long long i = 0; i < m; i++) {
            cities[i].resize(2);

            for (long long j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
