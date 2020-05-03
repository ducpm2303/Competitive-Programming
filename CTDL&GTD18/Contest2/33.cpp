#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int x[100];
int n;
int ans = 0;
map < int, bool > a, b, c;


void Try(int i) {
    for (int j = 1 ; j <= n; j++) {
        if (!a[j] && !b[i + j] && !c[i - j]) {
            x[i] = j;
            if (i == n) ans++;
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
    cin >> n;
    Try(1);
    cout << ans;   
}