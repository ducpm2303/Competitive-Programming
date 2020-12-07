/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
void Input(){
    //cin >> s;
}

void Solve(){
    while(cin >> s){
        int n = s.length();
        vector<int> dpa(n+1,0), dpb(n+1,0);
        for(int i = 1; i <= n; i++){
            if(s[i-1] == 'A'){
                dpa[i] = dpa[i-1] + 1; 
                dpb[i] = dpb[i-1];
            }
            else {
                dpb[i] = dpb[i-1] + 1;
                dpa[i] = dpa[i-1];
            }
        }
        for(int len = n; len >= 1; len--){
            int flag = true;
            for(int i = 0; i <= n - len; i++){
                //cout << s.subs    tr(i,len) << '\n';
                if(abs((dpa[i+len] - dpa[i]) - (dpb[i+len] - dpb[i])) <= 1){
                    cout << len << '\n';
                    flag = false;
                    break;
                }
            }
            if(flag == false) break;
        }
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
