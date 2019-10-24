/**Author : Vivek Bhardwaj
 * Question available at the link below : 
 * https://www.hackerrank.com/challenges/bfsshortreach/problem
 **/


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<long long> bfs(long long n, long long m, vector<vector<long long>> edges, long long s) {
    s--;
    vector<long long> dist(n,-1);
    dist[s]=0;
    vector<bool> visited(n,false);
    vector<vector<int>> v(n);

    for(auto i : edges){
        v[--i[0]].push_back(--i[1]);
        v[i[1]].push_back(i[0]);

    }
    visited[s]=true;
    queue<long long> q;
    q.push(s);
    while(!q.empty()){
        for(auto i : v[q.front()]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
                dist[i]=dist[q.front()]+6;
            }
        }
        q.pop();
    }
    return dist;
}

int main()
{

    long long q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (long long q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        long long n = stoi(nm[0]);

        long long m = stoi(nm[1]);

        vector<vector<long long>> edges(m);
        for (long long i = 0; i < m; i++) {
            edges[i].resize(2);

            for (long long j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long long s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<long long> result = bfs(n, m, edges, s);

        for (long long i = 0; i < result.size(); i++) {
            if(result[i]==0) continue;
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }


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
