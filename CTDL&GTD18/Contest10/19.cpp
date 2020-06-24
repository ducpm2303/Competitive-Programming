/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define III pair <int,pair <int,int>>
const int MAX = 500;

priority_queue < III, vector < III >, greater < III > > min_heap;
int dist[MAX + 5][MAX + 5];
int a[MAX + 5][MAX + 5];
int dx[10] = {0, 0, -1, 1};
int dy[10] = {1, -1, 0, 0};
int n, m;
void dijkstra(int x, int y) {
	dist[x][y] = a[x][y];
	min_heap.push(make_pair(a[x][y], make_pair(x, y)));
	while (!min_heap.empty()) {
		auto cur = min_heap.top();
		min_heap.pop();
		int c = cur.first;
		int x = cur.second.first;
		int y = cur.second.second;
		for (int i = 0 ; i < 4; i++) {
			int u = x + dx[i];
			int v = y + dy[i];
			if (1 <= u && u <= n && 1 <= v && v <= m) {
				if (dist[u][v] > c + a[u][v]) {
					dist[u][v] = c + a[u][v];
					min_heap.push(make_pair(dist[u][v], make_pair(u, v)));
				}
			}
		}
	}
}
void Input(){
    cin >> n >> m;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; j <= m; j++) {
            dist[i][j] = 1E9;
        }
    }
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}
void Solve(){
    dijkstra(1, 1);
	cout << dist[n][m] << '\n';
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
