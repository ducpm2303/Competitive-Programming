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
int k;
string a, b; 
void Input(){
    cin >> k >> a >> b;
}   
void Solve(){
    int n = 0;
   	int m = 0;
   	for (int i = 0 ; i < a.length(); i++) {
   		n = n * k + (a[i] - '0');
   	}
   	for (int i = 0 ; i < b.length(); i++) {
   		m = m * k + (b[i] - '0');
   	}
   	int res = n + m;
   	vi ans;
   	while (res) {
   		ans.push_back(res % k);
   		res /= k;
   	}
   	for (int i = ans.size() - 1 ; i >=0; i--) {
   		cout << ans[i];
   	}
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

 