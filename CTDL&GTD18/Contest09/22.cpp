#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

int n, m;
vector<int> a[1005];
int cnt = 0, low[1005], num[1005];
int points = 0, bridges = 0;
set <pair<int,int> > mySet;
void dfs(int u, int p) {
    int children = 0;
    num[u] = low[u] = cnt++;
    for(int i = 0; i < a[u].size(); i++) {
    	int v = a[u][i];
        if (num[v] == -1) {
            children++;
            dfs(v, u);
            // u-v is bridges
            if (low[v] > num[u]){
                mySet.insert({min(u,v),max(u,v)});
            }
            low[u] = min(low[u], low[v]);
        } else if (v != p)
            low[u] = min(low[u], num[v]);
    }
}

int main() {
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) a[i].clear();
        mySet.clear();
        for(int i = 1; i <= m; i++) {         
            int u, v; cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        memset(num, -1, sizeof num);
        memset(low, 0, sizeof low);
        for(int u = 1; u <= n; u++)
            if (num[u] == -1) dfs(u, u);
        set <pair<int,int> > :: iterator it;
        for(it = mySet.begin(); it != mySet.end(); it++){
            cout << it->first << ' ' << it->second << ' ';
        }
        cout << '\n';
    }

    return 0;
}