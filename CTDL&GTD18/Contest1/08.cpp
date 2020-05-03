//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
int n , ok = 0;
vector < int > a;
void input(){
    cin >> n ; a.resize(n+1); ok = 0;
    for(int i = 1 ; i <= n ; i++)
        a[i] = n - i + 1;
}
void display(){
    for(int i = 1 ; i <= n ; i++){
        cout << a[i];
    }
    cout << ' ';
}
void gennext(){
    int i = n - 1;
    while(a[i] < a[i+1] && i >= 1) i--;
    if( i == 0) ok = 1;
    else{
        int pos = i + 1;
        int maxx = 0;
        for(int j = i + 1 ; j <= n ; j++){
            if(a[j] < a[i]){
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
 