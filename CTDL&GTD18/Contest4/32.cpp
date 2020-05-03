//Code By PMD
#include <bits/stdc++.h>
#define IOS                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
#define whatis(a) cout << #a " is " << (a) << endl;
using namespace std;

typedef long long i64;
const int N = 1e7 + 5;
const i64 mod = 1e9 + 7;
const i64 inf = 1e18 + 7;
i64 n;
vector<i64> f(N), a(N);
void update(int p)
{
	for (int i = p; i <= N; i += i & (-i))
		f[i]++;
}
i64 sum(int p)
{
	i64 res = 0;
	for (int i = p; i; i -= i & (-i))
		res += f[i];
	return res;
}

void solve()
{
	cin >> n;
	i64 res = 0, d = 1;
	for (int i = 0; i <= N; i++)
		f[i] = 0;
	map<i64, vector<int>> Down;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		Down[a[i]].push_back(i);
	}
	for (auto z : Down)
	{
		for (auto zz : z.second)
			a[zz] = d;
		d++;
	}
	for (int i = n; i >= 1; i--)
	{
		res += sum(a[i] - 1);
		update(a[i]);
	}
	cout << res;
}
main()
{
	IOS;
	int t = 1;

	cin >> t;
	while (t--)
	{
		solve();
		cout << endl;
	}
}
//Code By PMD
