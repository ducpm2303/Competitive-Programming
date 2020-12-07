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
#define maxn 1000005

int N;
int mat[1005][1005], bit[1005][1005];

// Function to update a 2D BIT. It updates the
// value of bit[l][r] by adding val to bit[l][r]
void update(int l, int r, int val)
{
    for (int i = l; i <= N; i += i & -i)
        for (int j = r; j <= N; j += j & -j)
            bit[i][j] += val;
}

// function to find cumulative sum upto
// index (l, r) in the 2D BIT
long long query(int l, int r)
{
    long long ret = 0;
    for (int i = l; i > 0; i -= i & -i)
        for (int j = r; j > 0; j -= j & -j)
            ret += bit[i][j];

    return ret;
}

// function to count and return the number
// of inversion pairs in the matrix
long long countInversionPairs()
{
    // the 2D bit array and initialize it with 0.
    memset(bit, 0, sizeof(bit));

    // v will store the tuple (-mat[i][j], i, j)
    vector<pair<int, pair<int, int> > > v;

    // store the tuples in the vector v
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)

            // Note that we are not using the pair
            // (0, 0) because BIT update and query
            // operations are not done on index 0
            v.push_back(make_pair(-mat[i][j],
                        make_pair(i+1, j+1)));

    // sort the vector v according to the
    // first element of the tuple, i.e., -mat[i][j]
    sort(v.begin(), v.end());

    // inv_pair_cnt will store the number of
    // inversion pairs
    long long inv_pair_cnt = 0;

    // traverse all the tuples of vector v
    int i = 0;
    while (i < v.size())
    {
        int curr = i;

        // 'pairs' will store the position of each element,
        // i.e., the pair (i, j) of each tuple of the vector v
        vector<pair<int, int> > pairs;

        // consider the current tuple in v and all its
        // adjacent tuples whose first value, i.e., the
        // value of –mat[i][j] is same
        while (curr < v.size() &&
               (v[curr].first == v[i].first))
        {
            // push the position of the current element in 'pairs'
            pairs.push_back(make_pair(v[curr].second.first,
                                      v[curr].second.second));

            // add the number of elements which are
            // less than the current element and lie on the right
            // side in the vector v
            inv_pair_cnt += query(v[curr].second.first,
                                  v[curr].second.second);

            curr++;
        }

        vector<pair<int, int> >::iterator it;

        // traverse the 'pairs' vector
        for (it = pairs.begin(); it != pairs.end(); ++it)
        {
            int x = it->first;
            int y = it->second;

            // update the positon (x, y) by 1
            update(x, y, 1);
        }

        i = curr;
    }

    return inv_pair_cnt;
}


int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    #endif
    int sotest;
    cin >> sotest;
    while(sotest--){
        cin >> N;
        FO(i,0,N) FO(j,0,N) cin >> mat[i][j];
        LL inv_pair_cnt = countInversionPairs();
        cout << inv_pair_cnt << endl;
    }


    return 0;
}
