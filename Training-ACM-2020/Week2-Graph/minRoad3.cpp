//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
const int N = 101;
const int inf = 1e9 + 1;
int n,k,m;
vector < int > d;
struct node{
	int v,w,c;
};
node add(int v , int w , int c){
	node tmp;
	tmp.v = v ; tmp.c = c;
	tmp.w = w;
	return tmp;
}
bool operator > (node a , node b){
	return a.c > b.c;
}
vector < node > ke[N];
void input(){
	cin >> k >> n >> m;
	d.resize(n+1);
	for(int i = 1; i <= n ; i++) ke[i].clear();
	int u,v,w,c;
	for(int i = 1; i <= m ; i++){
		cin >> u >> v >> w >> c;
		ke[u].push_back(add(v,w,c));
	}
}
void dijkstra(){
	priority_queue < node,vector <node> , greater <node> > q;
	for(int i = 1 ; i <= n ; i++) d[i] = inf;
	q.push(add(1,0,0));
	int u ,v, w, c, l ,cost ;
	while(!q.empty()){
		u = q.top().v;
		l = q.top().w;
		cost = q.top().c;
		q.pop();
		if ( l >= d[u] ) continue;
		d[u] = l;
		for(auto x : ke[u]){
			v = x.v;
			w = x.w;
			c = x.c;
			if ( cost + c > k) continue;
			q.push(add(v,l + w,cost+c));
		}
	}
}
void solve(){
	dijkstra();
	if ( d[n] == inf ) d[n] = -1;
	cout << d[n] << endl;
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	faster();int t=1; 
	cin>>t; cin.ignore();
	while(t--){ input();solve();}
	cerr << "\nRunning is : " << 1.0*clock()/1000 ;
	return 0;
}
//Code By PMD