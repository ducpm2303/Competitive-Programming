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
int test = 1 , MULTI_TEST = 0; 
int a,b;
pair<int,int> Find(int n){
    vi maxx,minn;
    while(n != 0){
        int b = n%10;
        if(b!=5 && b!=6){
            maxx.push_back(b);
            minn.push_back(b);
        }
        else{
            maxx.push_back(6);
            minn.push_back(5);
        }
        n/=10;
    }
    int sum1 = 0 , sum2 = 0;
    for(int i = maxx.size() - 1 ; i >= 0 ; i--){
        sum1 = sum1*10+maxx[i];
        sum2 = sum2*10+minn[i];
    }
    return make_pair(sum1,sum2);
}
void Input(){
    cin >> a >> b;
}   
void Solve(){
    ii an = Find(a);
    ii bn = Find(b);
    cout << an.second + bn.second << ' ' << an.first + bn.first << '\n';
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

 