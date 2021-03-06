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
vi a;
/*

*/
void Input(){
    cin >> n; a.resize(n);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}   
void Solve(){
    int pos[1005][2];
    vector<int> b = a;
    sort(all(a));
    /*
    0 1 2 3 4 5 6
    1 2 3 4 5 6 7
    */
    for(int i = 0 ; i < n; i++){
        pos[a[i]][0] = i;
        pos[a[i]][1] = n - 1 - i;
    }
    /*
    1 6 3 4 5 7 2 
    */
    for(int i = 0 ; i < n ; i++){
        if( i!= pos[b[i]][0] && i != pos[b[i]][1]){
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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

 