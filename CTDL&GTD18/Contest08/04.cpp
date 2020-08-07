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
    for(int i = 0; i < s.length(); i++){
        cnt[s[i]-'A']++;
    }
    priority_queue<int,vector<int> > q;
    for(int i = 0; i < 26; i++)
        if(cnt[i] != 0) q.push(cnt[i]);
    while(k != 0 && !q.empty()){
        int x = q.top(); q.pop();
        if(x > 0) q.push(x-1);
        k--;
    }
    ll res = 0;
    while(!q.empty()){
        int x = q.top(); q.pop();
        //cout << x << '\n';
        res += 1LL*x*x;
    }
    cout << res << '\n';
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
