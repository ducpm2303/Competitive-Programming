//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
string a;
int n,k;
vector < string > res;
void input(){
    cin >> n >> k; a.resize(n);
}

AAABA 
AAA
AAB
ABA

void check(){
    int ok = 0;
    for(int i = 0 ; i < n - k + 1 ; i++){ // tach thanh cac xau co do dai la k, i : 1 -> 3
        int cnt = 0;
        for(int j = i; j < i + k; j++){ //
            if( a[j] == 'A') cnt++;
        }
        if( cnt == k ) ok++;
    }
    if (ok == 1) res.push_back(a);
}
void Try(int i){
    for(char j = 'A' ; j <= 'B' ; j++){
        a[i] = j;
        if ( i == n - 1 ) check();
        else Try(i+1);
    }
}
void solve(){
    Try(0);
    cout << res.size() << endl;
    for(int i = 0 ; i < res.size() ; i++){
        cout << res[i] << endl;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    faster();
    int t=1;// cin>>t;
    while(t--){ input();solve();}
    cerr << "\nRunning is : " << 1.0*clock()/1000 ;
    return 0;
}
//Code By PMD
 