/**Author : Vivek Bhardwaj
 * Solution to the problem Journey to the moon
 * @https://www.hackerrank.com/challenges/journey-to-the-moon/problem
 **/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
long long journeyToMoon(long long n, vector<vector<long long>> astronaut) {
    vector<vector<long long>> g(n);
    
    for(long long i=0;i<astronaut.size();i++){
        g[astronaut[i][0]].push_back(astronaut[i][1]);
        g[astronaut[i][1]].push_back(astronaut[i][0]);
    }

    vector<bool> visited(n,false);
    vector<long long> ans;
    for(long long i=0;i<n;i++){
        if(visited[i]) continue;
        long long count=1;
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
        ans.push_back(count);
    }
    //for(auto i : ans) cout<<i<<" ";
    long long sum=ans[0],sol=0;
    for(long long i=1;i<ans.size();i++){
        sol+=sum*ans[i];
        sum+=ans[i];
    }

    return sol;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    long long n = stoi(np[0]);

    long long p = stoi(np[1]);

    vector<vector<long long>> astronaut(p);
    for (long long i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (long long j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

