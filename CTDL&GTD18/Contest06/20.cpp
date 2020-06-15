//Code By PMD
#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
/*
    mot mang dem so lan xuat hien.
    sap xep + tham lam.
*/
int n,k;
const int maxN = 1e5+5;
int a[maxN];
void input(){
    cin >> n >> k;
    for(int i = 0 ; i < n;  i++){
        cin >> a[i];
    }
}
void solve(){
    sort(a,a+n);
    i64 res = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        int id = upper_bound(a,a+n,a[i] + k - 1) - a;
        res += 1LL*(id - 1 - i);
        //cout << i << ' ' << id << endl;
    }
    cout << max(res,(long long)0) << endl;
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
 
