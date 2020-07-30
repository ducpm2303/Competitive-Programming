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
void Input(){
    cin >> n;
}   
/*
Giả sử có phương trình 
4y + 7z = n --> (4y + 7z)(mod 7) = n(mod 7)
-> 4y (mod 7) = n(mod 7) = x;
Tính chất đồng dư : 4y = (x + 7*p) 
(p >= 0 && x + 7*p <= n)
Tìm ra cặp nghiệm y,z đầu tiên thỏa mãn phương trình 
*/
void Solve(){
    int x = n%7;
    int p = 0;
    while(x + 7*p <= n){
        if((x+7*p)%4 == 0){
            int y = (x+7*p)/4;
            int z = (n-y*4)/7;
            for(int i = 0 ; i < y ; i++) cout << 4 ;
            for(int i = 0 ; i < z ; i++) cout << 7 ;
            cout << '\n';
            return;
        }
        p++;
    }
    cout << -1 << '\n';


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

 