/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[1001][1001];
void Input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
}
void Solve(){
    vector<int> ke[n+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j]) ke[i+1].push_back(j+1);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < ke[i].size(); j++){
            cout << ke[i][j] << ' ';
        }
        cout << '\n';
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
