//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
int n,s ;
vector < int > a;
void input(){
    cin >> n >> s; a.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
}
void solve(){
    sort(a.begin(),a.end());
    int res = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(s > a[i]){
            int tmp = s/a[i];
            s -= tmp*a[i];
            res += tmp;
        }
    }
    cout << res ;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    faster();
    int t=1; //cin>>t;
    while(t--){ input();solve();}
    cerr << "\nRunning is : " << 1.0*clock()/1000 ;
    return 0;
}
//Code By PMD
 