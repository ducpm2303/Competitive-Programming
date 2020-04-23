#include <bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE "ONLINE_JUDGE"
#define setIO()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define X first
#define Y second
#define mp make_pair
typedef pair<double, double> point;
typedef pair<double, int> rec;
const int N = 100005;
int test = 1, MULTI_TEST = 1;
set<rec> S;
point a[N];
int n;
double range(const point &a, const point &b)
{
    double aa = a.X - b.X;
    double bb = a.Y - b.Y;

    return sqrt(aa * aa + bb * bb);
}
void Input()
{
    cin >> n;
    S.clear();
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;
}
void Solve()
{
    sort(a, a + n);
    int j = 0;
    double ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        while (a[i].X - a[j].X > ans)
        {
            S.erase(S.find(mp(a[j].Y, j)));
            j++;
        }
        set<rec>::iterator it = S.lower_bound(mp(a[i].Y - ans, 0));
        set<rec>::iterator ed = S.upper_bound(mp(a[i].Y + ans, 0));
        //cout << it->X << ' ' << it->Y << '\n';
        while (it != ed)
        {
            ans = min(ans, range(a[i], a[it->Y]));
            it++;
        }
        S.insert(mp(a[i].Y, i));
    }
    cout << setprecision(6) << fixed << ans << '\n';
}
int main()
{
    setIO();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    if (MULTI_TEST == 1)
        cin >> test;
    for (int i = 1; i <= test; i++)
    {
        Input();
        Solve();
    }
    return 0;
}
