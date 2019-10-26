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



int main(){
	int parent[1000];
	memset(parent,-1,sizeof(parent));
	union1(1,2,parent);
	for(int i=0;i<10;i++) cout<<parent[i]<<" ";
	cout<<"\n";
	union1(2,3,parent);
	for(int i=0;i<10;i++) cout<<parent[i]<<" ";
	cout<<"\n";
	union1(4,5,parent);
	for(int i=0;i<10;i++) cout<<parent[i]<<" ";
	cout<<"\n";
	union1(3,5,parent);
	for(int i=0;i<10;i++) cout<<parent[i]<<" ";
	cout<<"\n";
	union1(7,8,parent);
	for(int i=0;i<10;i++) cout<<parent[i]<<" ";
	cout<<"\n";
	union1(7,5,parent);
	for(int i=0;i<10;i++) cout<<parent[i]<<" ";
	cout<<"\n";
	return 0;
}
