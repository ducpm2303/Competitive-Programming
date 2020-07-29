#include<bits/stdc++.h>
using namespace std;
int n, ok = 0 , sum = 0;
vector < int > a;
void input(){
    cin >> n; a.resize(n);
    ok = 0 , sum = 0; // 
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}
void Try(int i , int s ){
    if(ok == 1) return;
    if ( s == sum/2 ){
        ok = 1;
        return;
    }
    int j = i + 1;
    while((s + a[j]) <= sum/2 && j < n){
        Try(j,s+a[j]);
        j++;
    }
}
void solve(){
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
    }
    if( sum % 2 == 1){
        cout << "NO" << '\n';
        return;
    }
    Try(-1,0);
    if(ok == 1) cout << "YES" << '\n';
    else cout << '\n';
}
int main(){
    int t=1; cin>>t;
    while(t--){ input();solve();}
    return 0;
}