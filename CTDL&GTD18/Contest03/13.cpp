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
int d;
string s;
bool cmp( pair<char,int > a ,  pair<char,int > b){
    return a.second > b.second;
}
void Input(){
    cin >> d >> s;
}   
void Solve(){
    map < char , int > cnt;
    for(int i = 0 ; i < s.length() ; i++)
        cnt[s[i]]++;
    vector < pair<char,int >> tmp;
    for(auto z : cnt) tmp.push_back(z);
    sort(all(tmp),cmp);
    int p = 0 ;
    for(auto z : tmp){
        //cout << z.first << '\n';
        int lastpos = p+(z.second-1)*d;
        if(lastpos >= s.length()){
            cout << -1 << '\n';
            return;
        }
        p++;
    }
    cout << 1 << '\n';
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

 