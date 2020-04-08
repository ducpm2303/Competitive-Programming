//Code By PMD
#include<bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long i64;
int n,k;
vector < int > a;
vector < vector <int> > res;
void input(){
    cin >> n >> k ;
    a.resize(n); res.clear();
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];

}
void Try(int i , int s , vector<int> mv){
    if( i > n || s > k) return;
    if ( s == k ){
        res.push_back(mv);
        return;
    }
    int j = i + 1;
    while((s + a[j] )<= k && j < n){
        mv.push_back(a[j]);
        Try(j,s+a[j],mv);
        mv.pop_back();
        j++;
    }
}
void solve(){
    sort(a.begin(),a.end());
    vector < int > move;
    Try(-1,0,move);
    if( res.size() == 0 ){
        cout << -1 << '\n';
        return;
    }
    for(auto z : res){
        cout << '[';
        for(int i = 0 ; i < z.size() ; i++){
            cout << z[i];
            if( i == z.size() - 1) cout << "]";
            cout << ' ';
        }
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
 