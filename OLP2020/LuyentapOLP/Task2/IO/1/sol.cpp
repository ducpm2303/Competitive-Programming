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


const double PI = 2*acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const LL Linfi = 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 1000005



int nxt[maxn];
int kq[maxn],dem=0;
string P, T;
int M,N;

void initKMP()
{
    nxt[0] = -1;
    int j = -1;
    FO (i,1,M)
    {
        while (j>-1 && P[i]!=P[j+1]) j = nxt[j];
        if (P[i] == P[j+1]) j++;
        nxt[i] = j;
    }
}

int process()   //T=Text; P=Pattern
{
    int j = -1;
    FO (i,0,N)
    {
        while (j>-1 && T[i]!=P[j+1]) j = nxt[j];
//tim xau P[1..j] la suffix cuaT[1..i-1] va P[j+1] == T[i]
        if (T[i] == P[j+1]) j++;
        if (j >= M-1)
        {
            return 1;
            j = nxt[j]; //khi tim thay roi thi dich luon
        }
    }
    return 0;
}



int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
#endif
    int sotest;
    cin >> sotest;
    while(sotest--)
    {
        cin >> T >> P;
        N = T.size();
        M = P.size();
        initKMP();
        if(process()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}
