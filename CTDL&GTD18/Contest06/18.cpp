//Code By PMD
#include<bits/stdc++.h>
using namespace std;
/*
    nhap luon mang a r sap xep
*/
const int maxN = 2*1e6+5;
int n,m;
int a[maxN];
void input(){
    cin >> n >> m;
    for(int i = 0 ; i < n + m; i++)
        cin >> a[i];
}

void solve(){
    sort(a,a+n+m);
    for(int i = 0 ; i < m + n ; i ++)
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
 