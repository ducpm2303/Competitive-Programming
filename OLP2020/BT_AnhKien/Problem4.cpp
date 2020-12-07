/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,x,y,m;
void Input(){
    cin >> a >> b >>  x >> y >> m;
}
string convert(string s){
    string res = "";
    for(int i = 0; i < s.length(); i++){
        res += s[i];
        int cnt = 1, check = 0;
        for(int j = i + 1; j < s.length(); j++){
            if(s[i] == s[j]) cnt ++;
            else{
                i = j - 1;
                check = 1;
                if(cnt > 1) res += to_string(cnt);
                break; 
            }
        }
        if(cnt > 1 && check == 0){
            res += to_string(cnt);
            break;
        }
    }
    return res;
}
void Solve(){
    ll gcd1 = __gcd(a,b);
    ll gcd2 = __gcd(x,y);
    if(gcd1 != gcd2 || max(x,y) > m){
        cout << -1 << '\n';
        return;
    }
    string res = "", res2 = "";
    while(a != b){
        if(a >= b) {a -= b; res += 'S';}
        else{swap(a,b);res += 'W';}
    }
    // cout << a << ' ' <<  b << '\n';
    while(x != y){
        if(x >= y) {x -= y; res2 += 'P';}
        else{swap(x,y); res2 += 'W';}
    }
    reverse(res2.begin(),res2.end());
    cout << convert(res) + convert(res2)<< '\n';
   
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
