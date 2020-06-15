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
int cnt[maxN] = {0};
bool cmp(int x , int y){
    if( cnt[x] == cnt[y]) return ( x < y);
    else return ( cnt[x] > cnt[y]);
}
void input(){
    cin >> n ;
    for(int i = 0 ; i < n;  i++)
        cin >> a[i];
    memset(cnt,0,sizeof cnt);
}
void solve(){
    for(int i = 0 ; i < n ; i++) cnt[a[i]]++;
    sort(a,a+n,cmp);
    for(int i = 0 ; i < n ; i++)
        cout << a[i] << ' ';
    cout << endl;
    
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
 