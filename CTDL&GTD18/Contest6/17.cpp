//Code By PMD
#include<bits/stdc++.h>
using namespace std;
/*
    tim maxa * minb,
*/
const int maxN = 1e6+5;
int n,m;
long long a[maxN] , b[maxN];
void input(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < m ; i++)
        cin >> b[i];
}

void solve(){
    long long maxa = *max_element(a,a+n);
    long long minb = *min_element(b,b+m);
    cout << 1LL*(maxa*minb) << endl;
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
 