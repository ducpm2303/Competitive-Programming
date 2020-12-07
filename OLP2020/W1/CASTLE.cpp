/*author : mdp*/

#include <bits/stdc++.h>
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
int m, n, ccc = 0;
vector<vector<int>> board;
vector<vector<int>> cellNo;
vector<vector<bool>> visited;
vector<vector<bool>> N, E, W, S;
vector<ld> cellArea;
vector<vector<ld>> area;
vector<vector<vector<pii>>> adj;
void Input(){
    cin >> m >> n;
	board.resize(m, vector<int>(n, 0));
	area.resize(m, vector<ld>(n, 0));
	visited.resize(m, vector<bool>(n, 0));
	N.resize(m, vector<bool>(n, 0)); E.resize(m, vector<bool>(n, 0)); W.resize(m, vector<bool>(n, 0)); S.resize(m, vector<bool>(n, 0));
	adj.resize(m, vector<vector<pii>>(n, vector<pii>(0)));
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cin >> board[i][j];
			N[i][j] = true; E[i][j] = true; W[i][j] = true; S[i][j] = true;
			if (board[i][j] % 2 == 0) W[i][j] = false; if (((int)board[i][j] / 2) % 2 == 0) N[i][j] = false;
			if (((int)((int)board[i][j] / 2) / 2) % 2 == 0) E[i][j] = false; if (((int)((int)((int)board[i][j] / 2) / 2) / 2) % 2 == 0) S[i][j] = false;
			ld dim1 = 1.0, dim2 = 1.0;
			if (N[i][j]) dim1 -= 0.1; if (S[i][j]) dim1 -= 0.1; if (W[i][j]) dim2 -= 0.1; if (E[i][j]) dim2 -= 0.1;
			area[i][j] = dim1 * dim2;
			if (!N[i][j] && i-1 >= 0) {				
				adj[i][j].pub(mp(i-1, j));
			}
			if (!E[i][j] && j+1 < n) {
				//cout << i << " " << j+1 << endl;
				adj[i][j].pub(mp(i, j+1));
			}
			if (!W[i][j] && j-1 >= 0) {
				//cout << i << " " << j-1 << endl;
				adj[i][j].pub(mp(i, j-1));
			}
			if (!S[i][j] && i+1 < m) {
				//cout << i+1 << " " << j << endl;
				adj[i][j].pub(mp(i+1, j));
			}
		}
	}
}

void Solve(){
    cellNo.resize(m, vector<int>(n, 0));
	cellArea.resize(m*n+1, 0);
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (!visited[i][j]) {
				cellNo[i][j] = ++ccc; cellArea[ccc] += area[i][j];
				visited[i][j] = true;
				queue<pii> Q; Q.push(mp(i,j));
				while (!Q.empty()) {
					pii tmp = Q.front(); Q.pop();
					for (ll i=0; i<adj[tmp.fi][tmp.se].size(); i++) {
						pii qq = adj[tmp.fi][tmp.se][i];
						if (!visited[qq.fi][qq.se]) {
							visited[qq.fi][qq.se] = true;
							cellNo[qq.fi][qq.se] = ccc;
							cellArea[ccc] += area[qq.fi][qq.se];
							Q.push(qq);
						}
					}
				}
			}
		}
	}
	
	ld task2 = *max_element(cellArea.begin()+1, cellArea.begin()+ccc+1), task3 = task2;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (N[i][j] && i-1 >= 0) {
				ld dim1c = 1.0, dim1x = 1.0;
				if (E[i][j]) dim1c -= 0.1; if (W[i][j]) dim1c -= 0.1;
				if (E[i-1][j]) dim1x -= 0.1; if (W[i-1][j]) dim1x -= 0.1;
				ld newArea = cellArea[cellNo[i][j]] + cellArea[cellNo[i-1][j]] + (dim1c + dim1x) * 0.1;
				if (cellNo[i][j] == cellNo[i-1][j]) newArea = cellArea[cellNo[i][j]] + (dim1c + dim1x) * 0.1;
				task3 = max(task3, newArea);
			}
			if (S[i][j] && i+1 < m) {
				ld dim1c = 1.0, dim1x = 1.0;
				if (E[i][j]) dim1c -= 0.1; if (W[i][j]) dim1c -= 0.1;
				if (E[i+1][j]) dim1x -= 0.1; if (W[i+1][j]) dim1x -= 0.1;
				ld newArea = cellArea[cellNo[i][j]] + cellArea[cellNo[i+1][j]] + (dim1c + dim1x) * 0.1;
				if (cellNo[i][j] == cellNo[i+1][j]) newArea = cellArea[cellNo[i][j]] + (dim1c + dim1x) * 0.1;
				task3 = max(task3, newArea);
			}
			if (E[i][j] && j+1 < n) {
				ld dim1c = 1.0, dim1x = 1.0;
				if (N[i][j]) dim1c -= 0.1; if (S[i][j]) dim1c -= 0.1;
				if (N[i][j+1]) dim1x -= 0.1; if (S[i][j+1]) dim1x -= 0.1;
				ld newArea = cellArea[cellNo[i][j]] + cellArea[cellNo[i][j+1]] + (dim1c + dim1x) * 0.1;
				if (cellNo[i][j] == cellNo[i][j+1]) newArea = cellArea[cellNo[i][j]] + (dim1c + dim1x) * 0.1;
				task3 = max(task3, newArea);
			}
			if (W[i][j] && j-1 >= 0) {
				ld dim1c = 1.0, dim1x = 1.0;
				if (N[i][j]) dim1c -= 0.1; if (S[i][j]) dim1c -= 0.1;
				if (N[i][j-1]) dim1x -= 0.1; if (S[i][j-1]) dim1x -= 0.1;
				ld newArea = cellArea[cellNo[i][j]] + cellArea[cellNo[i][j-1]] + (dim1c + dim1x) * 0.1;
				if (cellNo[i][j] == cellNo[i][j-1]) newArea = cellArea[cellNo[i][j]] + (dim1c + dim1x) * 0.1;
				task3 = max(task3, newArea);
			}
		}
	}
	cout << ccc << endl;
	cout << fixed << setprecision(2) << task2 << endl;
	cout << fixed << setprecision(2) << task3;
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
