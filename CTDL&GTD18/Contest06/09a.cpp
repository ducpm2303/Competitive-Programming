/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a;
int n,k;
void Input(){
    cin >> n >> k; a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void Solve(){
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] + a[j] == k) cnt ++;
        }
    }
    cout << cnt << '\n';
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
