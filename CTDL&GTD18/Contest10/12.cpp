#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > dsk;
int V,E,m;
int a,b;

bool isSafe(int v,int color[],int c){
	for(int i=0;i<dsk[v].size();i++){
		if(c==color[dsk[v][i]]){
			return false;
		}
	}
	return true;
}

bool Try(int m,int color[],int v){
	if(v==V+1) return true;
	for(int c=1;c<=m;c++){
		if(isSafe(v,color,c)){
			color[v]=c;
			if(Try(m,color,v+1)) return true;
			color[v]=0;
		}
	}
	return false;	
}

void xuLy(){
	dsk.clear();
	dsk.resize(15);
	cin>>V>>E>>m;
	for(int i=1;i<=E;i++){
		cin>>a>>b;
		dsk[a].push_back(b);
		dsk[b].push_back(a);
	}
	int color[15];
	memset(color,0,sizeof(color));
	if(Try(m,color,1)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		xuLy();
	}
	return 0;
}