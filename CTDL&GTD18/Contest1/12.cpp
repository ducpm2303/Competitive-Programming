//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
string a;
int n,k;
void input(){
    cin >> n >> k; a.resize(n);
}
void check(){
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == '1') cnt++;
    }
    if( cnt == k ) cout << a << '\n';
}
void Try(int i){
    for(char j = '0' ; j <= '1' ; j++){
        a[i] = j;
        if ( i == n - 1 ) check();
        else Try(i+1);
    }
}
void solve(){
    Try(0);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    faster();
    int t=1; cin>>t;
    while(t--){ input();solve();}
    cerr << "\nRunning is : " << 1.0*clock()/1000 ;
    return 0;
}
//Code By PMD
 