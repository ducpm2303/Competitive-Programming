/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1001][1001] = {0};
void Input(){
    memset(a,0,sizeof(a));
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
                a[i][val] = 1;
                val = 0;
            }
            else val = val * 10 + (str[j] - '0');
        }   
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << ' ';
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
