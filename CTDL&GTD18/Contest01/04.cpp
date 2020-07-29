//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
string a;
int n;
void input(){
    cin >> n ; a.resize(n);
}
void Try(int i){
    for(int j = 'A' ; j <= 'B' ; j++){
        a[i] = j;
        if(i == n - 1) cout << a << ' ';
        else Try(i+1);
    }
}
void solve(){
    Try(0);
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
 