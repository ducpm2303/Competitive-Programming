#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<double,int>II;
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

const double PI = 2*acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const LL Linfi = 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 2005
using namespace std;

// 2D Binary Indexed Tree. Note: global variable
// will have initially all elements zero
int n, cmd, a, b, u, v;
int bit[maxn][maxn];

// function to add a point at (x, y)
void update(int x, int y)
{
    int y1;
    while (x < maxn)
    {
        // x is the xth BIT that will be updated
        // while y is the indices where an update
        // will be made in xth BIT
        y1 = y;
        while ( y1 < maxn )
        {
            bit[x][y1]++;
            y1 += ( y1 & -y1 );
        }

        // next BIT that should be updated
        x += x & -x;
    }
}

// Function to return number of points in the
// rectangle (1, 1), (x, y)
int query(int x, int y)
{
    int res = 0, y1;
    while (x > 0)
    {
        // xth BIT's yth node must be added to the result
        y1 = y;
        while (y1 > 0)
        {
            res += bit[x][y1];
            y1 -= y1 & -y1;
        }
        // next BIT that will contribute to the result
        x -= x & -x;
    }
    return res;
}
int pointsInRectangle(int x1, int y1, int x2, int y2){
    return query(x2, y2) - query(x1 - 1, y2) -
           query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

// Returns count of triangles with n points, i.e.,
// it returns nC3
LL C3(int n)
{
    // returns pts choose 3
    return (1LL*n * (n - 1) * (n - 2)) / 6;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("4.in","r",stdin);
    freopen("4.out","w",stdout);
    #endif
    cin >> n;
    FOR(i,1,n){
        cin >> cmd;
        if(cmd == 1){
            cin >> a >> b;
            update(a, b);
        }
        else{
            cin >> a >> b >> u >> v;
            cout << C3(pointsInRectangle(a, b, u, v)) << endl;
        }
    }

    return 0;
}
