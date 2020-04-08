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
vector < int > Prime;
vector < bool > isPrime;
vector < vi > res;
int n,s,p;
void sieve(){
    isPrime.assign(200,true);
    for(int i = 2 ; i <= sqrt(200) ; i++){
        if( isPrime[i] == true){
            for(int j = i*i ; j <= 200 ; j += i)
                isPrime[j] = false;
        }
    }
    for(int i = 2 ; i <= 200 ; i++){
        if(isPrime[i] == true){
             Prime.push_back(i);
             //cout << i << ' ';
        }
    }
}
void Try(int i , int k ,  int sum , vector < int > mv){
    if( k == 0){
        if( sum == s ) res.push_back(mv);
        return;
    }
    for(int j = i + 1 ;  (sum + Prime[j]) <= s && j < Prime.size() ; j++){
        mv.push_back(Prime[j]);
        Try(j,k-1,sum + Prime[j],mv);
        mv.pop_back();
    }
}

void Input(){
    cin >> n >> p >> s;
    res.clear();
}   
void Solve(){
    int pos = lower_bound(all(Prime),p) - Prime.begin();
    vector < int > move;
    Try(pos-1,n,0,move);
    cout << res.size() << '\n';
    for(int i = 0 ; i < res.size() ; i++){
        for(int j = 0 ; j < res[i].size() ; j ++){
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    setIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    sieve();
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}

 