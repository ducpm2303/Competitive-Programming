#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 10005;

int cnt[N], dem[N];

int check(int n, int val) {
    int now = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > val) {
            int tmp = cnt[i]-val;
            if (now < tmp) return -1;
            now -= tmp;
            ans += tmp;
        }
        else now += val-cnt[i];
    }
    return ans;
}

void solve(int nt) {
    int n, c, m;
    scanf("%d%d%d", &n, &c, &m);

    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= c; i++) dem[i] = 0;

    while (m--) {
        int p, b;
        scanf("%d%d", &p, &b);
        cnt[p]++;
        dem[b]++;
    }

    int le = 0, ri = 0;
    for (int i = 1; i <= n; i++) ri = max(ri, cnt[i]);
    for (int i = 1; i <= c; i++) le = max(le, dem[i]);

    if (le >= ri) {
        ri = le;
    }

    while (le < ri) {
        int mi = (le+ri) >> 1;
        if (check(n,mi) >= 0) ri = mi;
        else le = mi+1;
    }

    printf("%d %d\n", le, check(n,le));
}

int main() {
    freopen("test.in","r",stdin);
    freopen("test.inp","w",stdout);
    int ct;
    scanf("%d", &ct);
    for (int nt = 1; nt <= ct; nt++) {
        solve(nt);
        //fprintf(stderr, "Case %d done.\n", nt);
    }
}
