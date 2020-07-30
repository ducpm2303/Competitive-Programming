/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE "ONLINE_JUDGE"
#define setIO()                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define all(a) a.begin(), a.end()
#define fill(x, b) memset((x), b, sizeof((x)))
#define fill2D(x, r, c, b) memset((x), b, sizeof(x[0][0]) * r * c)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vpii;
int test = 1, MULTI_TEST = 1;
string s;
void Input()
{
    cin >> s;
}
void Solve()
{
    vector<int> cnt(26, 0);
    for (int i = 0; i < s.length(); i++)
        cnt[s[i] - 'a']++;
    sort(cnt.begin(), cnt.end());
    int sum = 0;
    for (int i = 24; i >= 0; i--) sum += cnt[i];
    if (sum + 1 >= cnt[25])
        cout << 1 << endl;
    else cout << -1 << endl;
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
