/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005][1005];
void Input(){
   
}
void Solve(){
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 1 ; i <= n; i++) {
        string str;
        getline(cin, str);
        str += ' ';
        int val = 0;
        for (int j = 0 ; j < str.length(); j++) {
            if (str[j] == ' ') {
                a[i][val] = a[val][i] = 1;
                val = 0;
            } 
            else val = val * 10 + (str[j] - '0');
        }   
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(a[i][j] == 1){
                cout << i << ' ' << j << '\n';
            }
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
