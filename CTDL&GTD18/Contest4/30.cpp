
#include <bits/stdc++.h>

#define Faster()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
typedef long long i64;
typedef long double lb;
typedef pair<i64, i64> pt;
const int N = 1e5 + 5;
const i64 mod = 1e9 + 7;

struct matrix
{
    i64 pos[2][2];
    matrix()
    {
        pos[0][0] = 0;
        pos[0][1] = 1;
        pos[1][0] = 1;
        pos[1][1] = 1;
    }
};
matrix multi(matrix a, matrix b)
{
    matrix res;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            res.pos[i][j] = 0;
            for (int h = 0; h <= 1; h++)
                res.pos[i][j] = (res.pos[i][j] + a.pos[i][h] * b.pos[h][j] % mod) % mod;
        }
    }
    return res;
}
matrix powermod(matrix a, i64 n)
{
    if (n == 1)
        return a;
    if (n % 2 == 0)
        return powermod(multi(a, a), n / 2);
    return multi(a, powermod(multi(a, a), n / 2));
}
void Input()
{
}
void Solve()
{
    matrix a;
    i64 f1 = 1, f2 = 1;
    i64 n;
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << 1 << endl;
        return;
    }
    matrix b = powermod(a, n - 1);
    long long res = (b.pos[0][0] * f1 + b.pos[0][1] * f2) % mod;
    cout << res << endl;
}

main()
{
    Faster();
    int test = 1;
    cin >> test;
    while (test--)
    {
        Input();
        Solve();
        //cout<<endl;
    }
}
