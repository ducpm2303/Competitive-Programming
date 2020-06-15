/*author : mdp*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
vector<string> a;
string s,t;
int n;
void Input(){
    cin >> n >> s >> t; a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
}

void Solve(){
    int m = a[0].length();
    int cnt[26];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt[a[i][j]-'A']++;
        }
    }
    vector<char>b;
    for(int i = 0 ; i < 26; i++) if(cnt[i] != 0) b.push_back(char(i+'A'));
    unordered_map<string,int> stp;
    unordered_set<string> check(a.begin(),a.end());
    queue <string> q;
    q.push(s); stp[s] = 1;
    while(!q.empty()){
        string x = q.front(); q.pop();
        //cout << x << '\n';
        int d = stp[x];
        if(x == t) break;
        for(int i = 1; i <= m ; i++){
            for(int j = 0; j < b.size() ; j++){
                string tmp = x; tmp[i-1] = b[j];
                if(check.find(tmp) != check.end() && stp.find(tmp) == stp.end()){
                    stp[tmp] = d + 1;
                    q.push(tmp);
                }
            }
        }
    }
    //for(auto z : check) cout << z << '\n';
    cout << stp[t] << '\n';
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
