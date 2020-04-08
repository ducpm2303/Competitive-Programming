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

int x[100];
int ope[100];
int mark[100];
ll a[100];
bool ans = false;

bool update() {
    ll val;
    if (ope[1] == 1) val = a[x[1]] + a[x[2]];
    if (ope[1] == 2) val = a[x[1]] - a[x[2]]; 
    if (ope[1] == 3) val = a[x[1]] * a[x[2]];
    for (int i = 3 ; i <= 5; i++) {
        if (ope[i - 1] == 1) val += a[x[i]];
        if (ope[i - 1] == 2) val -= a[x[i]];
        if (ope[i - 1] == 3) val *= a[x[i]];
    }
    return val == 23;
}

void Try_bin(int i) {
    for (int j = 1 ; j <= 3; j++) {
        ope[i] = j;
        if (i == 4) ans |= update();
        else  Try_bin(i + 1);
    }
}

void Try(int i) {
    for (int j = 1 ; j <= 5; j++) {
        if (!mark[j]) {
            x[i] = j;
            mark[j] = true;
            if (i == 5) Try_bin(1);
            else Try(i + 1);
            mark[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1 ; i <= 5; i++) {
            cin >> a[i];
        }
        ans = false;
        Try(1);
        cout << (ans ? "YES" : "NO") << '\n';
    }
}