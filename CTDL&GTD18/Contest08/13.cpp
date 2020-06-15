/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+1;
vector<int> a(maxn);
int l,r;
bool checkDigits(int n){
    int cnt[10] = {0};
    while(n!=0){
        int b = n%10;
        if(b > 5) return false;
        cnt[b]++;
        if(cnt[b] > 1) return false;
        n/=10;
    }
    return true;
}
void Pre(){
    for(int i = 1; i < maxn ; i++){
        a[i] = (checkDigits(i) == true);
    }
}
void Input(){
    cin >> l >> r;
}
void Solve(){
    int cnt = 0;
    for(int i = l ; i <= r; i++){
        cnt += a[i];
    }
    cout << cnt << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    Pre();
    cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}
