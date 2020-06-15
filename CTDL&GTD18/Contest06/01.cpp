//Code By PMD
#include<iostream>
#include<algorithm>
using namespace std;
/*
    sap xep. + 2 con tro
*/
const int maxN = 1e3+5;
int a[maxN],n;
void input(){
    cin >> n;
    for(int i = 0 ; i < n ; i++) 
        cin >> a[i];
}
void solve(){
    sort(a,a+n);
    int l = 0 , r = n - 1;
    while(l < r){
        cout << a[r] << ' ' << a[l] << ' ';
        l++,r--;
    }
    if( l == r ) cout << a[l] ;
    cout << '\n';
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
 
