/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int n,m;
vector < int > prime(10001,0);
void sang(){
    prime[0] = prime[1] = 1;
    for (int i=2; i*i<= 10001; i++){
		if (!prime[i]){
			for (int j = i*i; j<10001; j+=i){
				prime[j]=1;
			}
		}
	}
}
int so(int x,int n,int t)
{
    if(t==1&&n==0) return 0;
    if(t==1) return (x-(x/1000)*1000+n*1000);
    if(t==2) return (x-((x/100)%10)*100+n*100);
    if(t==3) return (x-((x%100)/10)*10+n*10);
    if(t==4) return (x-x%10+n);
}
void Input(){   
    cin >> n >> m;
}
 
void Solve(){
    int vis[9999] = {0};
    queue <ii> q;
    q.push(ii(n,0));
    vis[n] = 1;
    while(!q.empty()){
        ii t = q.front(); q.pop();
        if(t.first == m){
             cout << t.second << '\n';
             return;
        }
        for(int i = 1; i <= 4; i++){
            for(int j = 0; j <= 9; j++){
                int u = so(t.first,j,i);
                if(u == 0) continue;
                if(vis[u] == 0 && prime[u] == 0){
                    vis[u] = 1;
                    q.push({u,t.second+1});
                }
            }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    sang();
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
