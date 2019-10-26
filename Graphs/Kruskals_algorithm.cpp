#include<bits/stdc++.h>
using namespace std;

int find1(int x,int * parent){
	if(parent[x]<0) return x;
	parent[x]=find1(parent[x],parent);
	return parent[x];
}

void union1(int x,int y,int * parent){
	int a=find1(x,parent);
	int b=find1(y,parent);
	if(a==b) return;
	if(parent[a]<parent[b])parent[b]=a;
	else if(parent[a]>parent[b])parent[a]=b;
	else {parent[a]--;parent[b]=a;}
}


struct edge{
    int from;
    int to;
    int weight;
    edge(int x,int y,int z){
        this->from=x;
        this->to=y;
        this->weight=z;
    }
};

vector<pair<int,int>> kruskals(vector<vector<pair<int,int>>> &v){
    //Creating Edge List from Adjacency List implementation
    vector<edge> edge_list;
    vector<pair<int,int>> ans;
    for(int it=0;it<v.size();it++){
        for(auto i : v[it]){
            edge_list.emplace_back(it,i.first,i.second);
        }
    }

    int parent[1000];
	memset(parent,-1,sizeof(parent));

    sort(edge_list.begin(),edge_list.end(),[](const edge &a,const edge &b){return a.weight <b.weight;});

    for(auto edge : edge_list){
        if(find1(edge.from,parent)==find1(edge.to,parent)){
            continue;
        }
        union1(edge.from,edge.to,parent);
        ans.emplace_back(edge.from,edge.to);
    }

    return ans;
}


int main(){

    vector<vector<pair<int,int>>> v(5);
    v[0].emplace_back(1,1);
    v[0].emplace_back(3,2);
    v[0].emplace_back(2,8);
    v[1].emplace_back(4,2);
    v[1].emplace_back(2,5);
    v[3].emplace_back(4,5);

    vector<pair<int,int>>ans =kruskals(v);

    for(auto edge : ans){
        cout<<edge.first<<"-->"<<edge.second<<"\n";
    }

    return 0;
}