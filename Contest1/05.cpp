//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
int n,k, ok = 0;
vector < int > a;
void input(){
    cin >> n >> k ; a.resize(k+1); ok = 0;
    for(int i = 1; i <= k ; i++) a[i] = i;
}
void display(){
    for(int i = 1 ; i <= k ; i++){
        cout << a[i] ;
    }
    cout << ' ';
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
    while(ok == 0){
        display();
        gennext();
    }
    cout << '\n';
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
 