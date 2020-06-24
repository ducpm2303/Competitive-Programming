/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dist[105][105];
int n, m;
void Input(){
	cin >> n >> m;
    for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= n; j++) {
				dist[i][j] = 1E9;
			}
		}
    for (int i = 0 ; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
    }
}
void Solve(){
    for (int i = 1 ; i <= n; i++) dist[i][i] = 0;
		for (int k = 1 ; k <= n; k++) {
			for (int i = 1 ; i <= n; i++) {
				for (int j = 1 ; j <= n; j++) {
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
		double ans = 0;
		int cnt = 0;
		for (int i = 1 ; i <= n; i++) {
			for (int j = 1 ; j <= n; j++) {
				if (dist[i][j] != 1E9 && dist[i][j] != 0) {
					ans += dist[i][j];
					cnt++;
				}
			}
		}
		printf("%0.2lf\n", ans / cnt);
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
