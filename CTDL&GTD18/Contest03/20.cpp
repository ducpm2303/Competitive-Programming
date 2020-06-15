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
    vector<int> pos;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '[')
            pos.push_back(i);
    int cnt = 0, res = 0, id = 0;
    for (int i = 0; i < s.length(); i++)
    {
        cnt += ((s[i] == '[') ? 1 : -1);
        id += (s[i] == '[');
        if (cnt < 0)
        {
            res += pos[id] - i;
            swap(s[pos[id]], s[i]);
            cnt = 1;
            id++;
        }
    }
    cout << res << '\n';
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
