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
string s,res;
int k;
void Try(string s , int k){
    if (k == 0) return;
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            if (s[i] < s[j]){
                swap(s[i],s[j]);
                res = max(res, s);
                Try(s,k-1);
                swap(s[i],s[j]);
            }
        }
    }
 
}
void Input(){
    cin >> k >>  s;
}   
void Solve(){
    res = s;
    Try(s,k);
    cout << res << '\n';
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

 