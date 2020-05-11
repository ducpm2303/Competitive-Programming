//Code By PMD
#include<iostream>
#include<algorithm>
using namespace std;
/*
    sap xep. + tham lam
*/
const int maxN = 1e5+5;
pair<int,int> a[maxN];
int n,x;

void input(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
        
}
void solve(){
    sort(a,a+n);
    int ans = 0;
    int vis[n] = {0};
    for (int i = 0; i < n; i++) { 
        if (vis[i] == 1 || a[i].second == i) 
            continue; 
        int cnt = 0; 
        int j = i; 
        while (vis[j] == 0){ 
            vis[j] = 1; 
            j = a[j].second; 
            cnt++; 
        } 
        if (cnt > 0) ans += (cnt - 1);
    } 
    cout << ans << '\n';
}
int main(){
    int t=1; 
    cin>>t; 
    while(t--){ 
        input();
        solve();
    }
    return 0;
}
//Code By PMD
 