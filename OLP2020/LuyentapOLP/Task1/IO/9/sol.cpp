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
#define maxn 4000005
#define max_elem 1000000

int n, x;
int segmentTree[maxn];

// Update 'node' and its children in segment tree.
// Here 'node' is index in segmentTree[], 'a' and
// 'b' are starting and ending indexes of range stored
//  in current node.
// 'diff' is the value to be added to value 'x'.
void update(int node, int a, int b, int x, int diff)
{
    // If current node is a leaf node
    if (a == b && a == x )
    {
        // add 'diff' and return
        segmentTree[node] += diff;
        return ;
    }

    // If current node is non-leaf and 'x' is in its
    // range
    if (x >= a && x <= b)
    {
        // update both sub-trees, left and right
        update(node*2, a, (a + b)/2, x, diff);
        update(node*2 + 1, (a + b)/2 + 1, b, x, diff);

        // Finally update current node
        segmentTree[node] = segmentTree[node*2] +
                            segmentTree[node*2 + 1];
    }
}

// Returns k'th node in segment tree
int findKth(int node, int a, int b, int k)
{
    // non-leaf node, will definitely have both
    // children; left and right
    if (a != b)
    {
        // If kth element lies in the left subtree
        if (segmentTree[node*2] >= k)
            return findKth(node*2, a, (a + b)/2, k);

        // If kth one lies in the right subtree
        return findKth(node*2 + 1, (a + b)/2  + 1,
                       b, k - segmentTree[node*2]);
    }

    // if at a leaf node, return the index it stores
    // information about
    return (segmentTree[node])? a : -1;
}

// insert x in the set
void insert(int x)
{
    update(1, 0, max_elem, x, 1);
}

// delete x from the set
void delet(int x)
{
    update(1, 0, max_elem, x, -1);
}

// returns median element of the set with odd
// cardinality only
int median()
{
    int k = (segmentTree[1] + 1) / 2;
    return findKth(1, 0, max_elem, k);
}


int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    #endif
    int Q;
    cin >> Q;
    while(Q--){
        string cmd;
        cin >> cmd;
        if(cmd == "add"){
            cin >> x;
            insert(x);
        }
        else if(cmd == "del"){
            cin >> x;
            delet(x);
        }
        else if(cmd == "print")
            cout << median() << "\n";

    }


    return 0;
}
