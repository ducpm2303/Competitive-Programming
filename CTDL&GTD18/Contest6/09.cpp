//Code By PMD
#include<bits/stdc++.h>
using namespace std;
/*
    chat nhi phan , 
    l = vi tri dau tien lon hon hoac bang x - a[i].
    r = vi tri dau tien lon hon x - a[i].
    
*/
typedef long long i64;
i64 n , x;
vector < int > a;
void input(){
    cin >> n >> x;
    a.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
}
void solve(){
    long long res = 0 ;
    sort(a.begin(),a.end());
   
    for(int i = 0  ; i < n  ; i++){
        int l = lower_bound(a.begin()+ i + 1,a.end(), x-a[i]) - a.begin();
        int r = upper_bound(a.begin()+ i + 1,a.end(), x-a[i]) - a.begin();
        res += 1LL*( r - l);
        //cout <<a[i] << ' ' <<  l << ' ' << r << ' ' << r - l << endl;
    }
    cout << res << endl;
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
 