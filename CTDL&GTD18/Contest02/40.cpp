#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
 
 
int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    const int N = 1 << n;
    vector <vector <int> > dp(N, vector <int> (n, INF));
    dp[1][0] = 0;
    for (int mask = 0; mask < N; mask++) {
        for (int v = 0; v < n; v++) {
            if (dp[mask][v] == INF) continue;
            for (int u = 0; u < n; u++) {
                if (mask & (1 << u)) continue;
                dp[mask | (1 << u)][u] = min(dp[mask | (1 << u)][u], dp[mask][v] + a[v][u]);
            }
        }
    }
    int res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[N - 1][i] + a[i][0]);
    }
    cout << res;
}
 