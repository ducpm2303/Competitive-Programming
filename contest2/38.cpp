/*author : mdp*/
#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE "ONLINE_JUDGE"
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define all(a) a.begin(),a.end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
#define div ___div

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vpii;
int test = 1 , MULTI_TEST = 1; 
// f[i][j] : so nho nhat co i uoc va duoc tao thanh tu j snt dau tien
// f[i][j] = f[i / (k + 1)][j - 1] * fpow(p[j], k) (k + 1 la cac uoc cua i)
 
const int MAX = 1e3;
const long long INF = 1e18;
int n;
long long f[MAX + 5][15];
int p[15] = {-1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
vector < int > div[MAX + 5];
long long fpow(int a, int b) {
    long long res = 1;
    for (int i = 0 ; i < b; i++) res *= a;
    return res;
}
void sieve(){
    for (int i = 1 ; i <= MAX; i++) {
        for (int j = 1 ; j <= sqrt(MAX); j++) {
            if (i % j == 0) {
                div[i].push_back(j);
                if (i / j != j) div[i].push_back(i / j);
            }
        }
    }
}
void Input(){
    cin >> n;
}   
void Solve(){
    for (int i = 1 ; i <= MAX; i++) {
            for (int j = 1 ; j <= 10; j++) {
                if (i == 1) f[i][j] = 1;
                else f[i][j] = LONG_LONG_MAX;
            }
        }
        for (int i = 1 ; i <= 60; i++) {
            f[i][1] = 1ll << i - 1;
        }
        for (int i = 2 ; i <= n; i++) {
            for (int j = 2 ; j <= 10; j++) {
                for (int k = 0 ; k < div[i].size(); k++) {
                    int x = log(INF) / log(p[j]);
                    x++;
                    if (div[i][k] - 1 < x) {
                        if (f[i / div[i][k]][j - 1] < INF / fpow(p[j], div[i][k] - 1)) {
                            f[i][j] = min(f[i][j], f[i / div[i][k]][j - 1] * fpow(p[j], div[i][k] - 1));
                        }
                    }
                }
            }
        }
        cout << f[n][10] << endl;
}
int main(){
    setIO();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    if(MULTI_TEST == 1) cin >> test;
    sieve();
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}

 