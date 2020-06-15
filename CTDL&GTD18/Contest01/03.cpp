//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
int n;
vector < int > a;
void input(){
    cin >> n ; a.resize(n+1);
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
}
void gennext(){
    int i = n - 1;
    while(a[i] > a[i+1] && i >= 1) i--;
    if( i == 0){
        for(int j = 1 ; j <= n ; j++)
            cout << j << ' ';
        cout << '\n';
        return;
    }
    else{
        int pos = i + 1;
        int maxx = 0;
        for(int j = i + 1 ; j <= n ; j++){
            if(a[j] > a[i]){
                if( a[j] > maxx ){
                    maxx = a[j];
                    pos = j;
                }
            }
        }
        swap(a[i],a[pos]);
        int l = i + 1 , r = n;
        while( l <= r ){
            swap(a[l],a[r]);
            l++,r--;
        }
        for(int j = 1 ; j <= n ; j++)
            cout << a[j] << ' ';
        cout << '\n';
    }
}
void solve(){
    gennext();
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
 