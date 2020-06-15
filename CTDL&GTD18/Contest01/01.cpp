//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
string x;
void input(){
    cin >> x;
}
void solve(){
    int i = x.length() - 1;
    while(x[i] == '1' && i >= 0){
        x[i] = '0';
        i--;
    }
    if ( i == -1){
        for(int i = 0 ; i < x.length() ; i++)
            cout << 0;
        cout << '\n';
        return;
    }
    else x[i] = '1';
    cout << x << '\n';
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
 