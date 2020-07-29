#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int x[100];
int n;
int ans = 0;
vector<bool> a(100),b(100),c(100);
void Try(int i) {
    for (int j = 1 ; j <= n; j++) {
        if (!a[j] && !b[i + j] && !c[i - j + n]) {
            x[i] = j;
            if (i == n) ans++;
            else {
                a[j] = true;
                b[i + j] = true;
                c[i - j + n] = true;
                Try(i + 1);
                a[j] = false;
                b[i + j] = false;
                c[i - j + n] = false;
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