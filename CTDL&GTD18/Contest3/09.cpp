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
int n;
bool vis[10000];
int res[10000];
struct CV{
    int ID;
    int dealine;
    int profit;
};
bool cmp(CV a,CV b){
    return (a.profit > b.profit);
}
CV a[10000];
void Input(){
    cin >> n;
    memset(vis,false,sizeof(vis));
    memset(res,0,sizeof(res));
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].ID >> a[i].dealine >> a[i].profit;
}
void Solve(){
    sort(a,a + n,cmp);
    for(int i = 0 ; i < n ; i++){
        for(int j = min(n ,a[i].dealine) - 1; j >= 0 ; j--){
            if( !vis[j] ){
                res[j] = i;
                vis[j] = true;
                break;
            }
        }
    }
    ll ress = 0;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(vis[i]){
            cnt++;
            ress += a[res[i]].profit;
        }
            
    }
    cout <<cnt << ' ' << ress << '\n';
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

 