#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n = 8;
int x[100];
int sum[100];
int val[100][100];
int ans = -1;
map < int, bool > a, b, c;

void Try(int i) {
    for (int j = 1 ; j <= n; j++) {
        if (!a[j] && !b[i + j] && !c[i - j]) {
            x[i] = j;
            sum[i] = sum[i - 1] + val[i][j];
            if (i == n) ans = max(ans, sum[n]);
            else {
                a[j] = true;
                b[i + j] = true;
                c[i - j] = true;
                Try(i + 1);
                a[j] = false;
                b[i + j] = false;
                c[i - j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1 ; i <= n; i++) {
            for (int j = 1 ; j <= n; j++) {
                cin >> val[i][j];
            }
        }
        ans = -1;
        Try(1);
        cout << ans << endl;
    }        
}