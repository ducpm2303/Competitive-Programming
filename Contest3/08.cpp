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
struct data{
    int l;
    int r;
};
 
bool cmp(data a,data b){
    return a.r < b.r;
}
 
void Solve(){
    int n;
    cin >> n;
    data s[n+5];
    for(int i=0;i<n;i++) cin >> s[i].l;
    for(int i=0;i<n;i++) cin >> s[i].r;
    sort(s,s+n,cmp);
    // for(int i=0;i<n;i++) cout <<  a[i].l<<" "<< a[i].r<<endl;
    int tmp=0;
    int ans=1;
    for(int i=1;i<n;i++){
        if(s[i].l>=s[tmp].r){
            ans++;
            tmp=i;
        }
    }
    cout << ans<<endl;
}
int main(){
    setIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){ Solve();}
    return 0;
}

 