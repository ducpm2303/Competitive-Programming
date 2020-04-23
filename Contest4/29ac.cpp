/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, double> point;
int n;
vector<point> a;
void Input()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
}
bool cmpY(point x, point y)
{
    return (x.second < y.second);
}
double range(point x, point y)
{
    double xx = x.first - y.first;
    double yy = x.second - y.second;
    return sqrt(xx * xx + yy * yy);
}
double bruteForce(int l, int r)
{
    double dmin = DBL_MAX;
    for (int i = l; i <= r - 1; i++)
        for (int j = i + 1; j <= r; j++)
            dmin = min(dmin, range(a[i], a[j]));
    return dmin;
}
double FindY(vector<point> b, double d)
{

    double dmin = d;
    sort(b.begin(), b.end(), cmpY);
    for (int i = 0; i < b.size() - 1; i++)
    {
        //cout << b[i].first << ' ' << b[i].second << '\n';
        int j = i + 1;
        while ((b[j].second - b[i].second) < dmin && j < b.size())
        {
            dmin = min(dmin, range(b[i], b[j]));
            j++;
        }
    }
    return dmin;
}
double FindX(int l, int r)
{
    if (r - l <= 3)
        return bruteForce(l, r);
    int mid = l + r >> 1;
    double dl = FindX(l, mid);
    double dr = FindX(mid + 1, r);
    double dmin = min(dl, dr), midP = a[mid].first;
    vector<point> stripA;
    for (int i = l; i <= r; i++)
    {
        if (abs(a[i].first - midP) < dmin)
            stripA.push_back(a[i]);
    }

    return min(dmin, FindY(stripA, dmin));
}

void Solve()
{
    sort(a.begin(), a.end());
    cout << setprecision(6) << fixed << FindX(0, n - 1) << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        Input();
        Solve();
    }

    return 0;
}
