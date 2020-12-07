/*author : mdp*/
/*
    maxPoint = 6/35
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n,m;
string s;
vector <int> ke[N]; 
int res[N] = {0};
map <vector<int>,vector<int>> color;
void Input(){
    cin >> n >> m;
    cin >> s;
	for(int i = 0 ; i < m ; i++){
		int u , v ;
		cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
}

void Solve(){
    for(int i = 1 ; i <= n ; i++){
		if( ke[i].size() == 0 ) continue;
        sort(ke[i].begin() , ke[i].end());
		color[ke[i]].push_back(i);
	}
    cout << color.size() << '\n';
    if (color.size() != 3){
        cout << "Impossible";
        return;
    }
    int cnt = 1;
    for(auto x : color){
        for(auto c : x.second) res[c] = cnt;
        cnt++;
    }
    for(int i = 1; i <= n; i++){
        if(res[i] == 0) res[i] = 1;
    }
    for(int i = 1 ; i <= n ; i++){
        if(res[i] == 1) cout << "R";
        else if(res[i] == 2) cout << "G";
        else cout << "B";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}