/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void Input(){
    
}
void Solve(){
    int V,E;
    cin>>V>>E;
    cin.ignore();
    vector<vector<int> > G(V+1,vector<int>(0));
    for(int i=1;i<=E;i++){
        int u,v;cin>>u>>v;cin.ignore();
        G[u].push_back(v);//cout<<u<<' '<<v<<endl;
        // G[v].push_back(u);
    }
    for(int i=1;i<=V;i++){
        sort(G[i].begin(),G[i].end());
        // G[i].resize(unique(G[i].begin(),G[i].end())-G[i].begin());
        cout<<i<<": ";
        for(auto z:G[i])cout<<z<<' ';cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
