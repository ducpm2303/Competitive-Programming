//Code By PMD
#include<iostream>
#include<algorithm>
using namespace std;
/*
    sap xep
*/
const int maxN = 1e5+5;
int a[maxN],n;

void input(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
 
}
void solve(){
    sort(a,a+n);
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
 