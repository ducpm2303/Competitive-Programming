/*author : mdp*/
#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE "ONLINE_JUDGE"
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define all(a) a.begin(),a.end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vpii;
int test = 1 , MULTI_TEST = 1; 
struct phanso{
    ll t,m;
};

phanso md(phanso a){
    ll gcd = __gcd(a.t,a.m);
    phanso res;
    res.t = a.t/gcd;
    res.m = a.m/gcd;
    return res;
}
phanso sub(phanso a , phanso b){
    phanso res ;
    res.t = a.t*b.m - b.t*a.m;
    res.m = a.m*b.m;
    return ( md(res) );
}
ll p,q;
void Input(){
    cin >> p >> q;
}   
void Solve(){
    phanso a;
    a.t = p ; a.m = q;
    a = md(a);
    int pos = 2;
    vector < phanso > res;
    while( a.t != 1){
        phanso b ;
        while(a.t*pos <= a.m) pos++;
        b.t = 1 , b.m = pos;
        a = sub(a,b);
        res.push_back(b);
    }
    res.push_back(a);
    for(int i = 0 ; i < res.size() ; i++){
        cout << res[i].t << '/' << res[i].m ;
        if( i != res.size() - 1) cout << " + ";
    }
    cout << '\n';
}
int main(){
    setIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}

 