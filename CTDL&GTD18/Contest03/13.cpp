/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;
string s;
void Input(){
    cin >> k >> s;
}

void Solve(){
    int cnt[26] = {0};
    int dem = 0;
    for(int i = 0; i < s.length(); i++){
        cnt[s[i]-'A']++;
        dem = max(dem,cnt[s[i]-'A']);
    }
    int n = s.length();
    if((dem-1)*k <= n - 1) cout << 1 << '\n';
    else cout << -1 << '\n';
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
