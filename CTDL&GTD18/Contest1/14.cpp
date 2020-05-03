//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
int n,k, ok = 0;
vector < int > a,b;
void input(){
    cin >> n >> k ; a.resize(k+1);
    b.resize(k+1); ok = 0;
    for(int i = 1 ; i <= k ; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    
}
void gennext(){
    int i = k;
    while(a[i] == n - k + i && i >= 1) i--;
    if( i == 0 ) ok = 1;
    else{
        a[i]++;
        for(int j = i + 1 ; j <= k ; j++){
            a[j] = a[j-1] + 1;
        }
    }
}
void solve(){
    gennext();
    if( ok == 1){
        cout << k << '\n';
    }
    else{
        int res = 0;
        for(int i = 1 ; i <= k ; i++){
            for(int j = 1 ; j <= k ; j++){
                if(a[i] == b[j]) res++;
            }
        }
        cout << k - res << '\n';
    }
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
 