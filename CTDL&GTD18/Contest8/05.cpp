/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void Input(){
    cin >> n;
}
void Solve(){
    for(int i = 1; i <= n; i++){
        string bin;
        int x = i;
        while(x != 0){
            bin += x%2 + '0';
            x >>= 1;
        }
        reverse(bin.begin(),bin.end());
        cout << bin << ' ';
    }
    cout << '\n';
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
