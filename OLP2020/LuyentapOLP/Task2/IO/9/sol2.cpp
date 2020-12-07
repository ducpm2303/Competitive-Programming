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

typedef pair<int,int>II;

const long double PI = 2*acos(0.0);
const long double eps = 1e-6;
const int infi = 1e9;
const LL Linfi = 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 200005

int n, m, ST, EN, Q;
int w[maxn], gg[maxn], p[maxn], x[maxn], Rp[maxn], R[maxn];
int nex[maxn], xet[maxn], parent[maxn], cost[maxn];
LL sum[maxn],f[maxn][20], g[maxn][20], sumdis[maxn], weight[maxn];
vector<int> adj[maxn], leaves;

void init_rmq(){
    FOR (i,1,n) f[i][0] = p[i];
    for (int j = 1; (1<<j) <= n; j++)
    for (int i=1; i+(1<<j)-1 <= n; i++)
        f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);

    FOR (i,1,n) g[i][0] = sum[i];
    for (int j = 1; (1<<j) <= n; j++)
    for (int i=1; i+(1<<j)-1 <= n; i++)
        g[i][j] = max(g[i][j-1], g[i+(1<<(j-1))][j-1]);
}

LL get_minp(int i,int j){
    if(i>j) return 0;
    int k = log2(j-i+1); /// 31 - __builtin_clz(j-i+1)
    return min(f[i][k], f[j-(1<<k)+1][k]);
}

LL get_max_sum(int i, int j){
    if(i>j) return 0;
    int k = log2(j-i+1); /// 31 - __builtin_clz(j-i+1)
    return max(g[i][k], g[j-(1<<k)+1][k]);
}

int findZ(int v, int u, int &min1){
    min1 = infi;
    int pos1 = -1;
    FOR(i,v+1,u){
        if(p[i] < min1){
            min1 = p[i]; pos1 = i;
        }
    }
    int pos2 = Rp[pos1];
    LL maxx = get_max_sum(v+1, pos2-1);
    int pos3 = 0;
    FORD(i,pos2-1,v) {
        if(sum[i] == maxx){
            pos3 = i;
            break;
        }
    }
    return pos3;
}

void DFS(int u){
    xet[u] = 1;
    FO(i,0,adj[u].size()){
        int v = adj[u][i];
        if(xet[v] == 0){
            if(u != n){
                sumdis[v] = sum[u] - sum[v] + sumdis[u];


                int z = nex[v];
                if(z == n) z = u;

                //cout << v << " " << u << " : " << z << " "<< sum[z]<< endl;
                weight[v] = (sum[z]-sum[v])*cost[v] + weight[z];
                ///weight[v] = (sum[z]-sum[v])*min1 + weight[z];
            }
            DFS(v);
        }
    }
}

void DFS2(int u){
    xet[u] = 1;
    FO(i,0,adj[u].size()){
        int v = adj[u][i];
        if(xet[v] == 0){
            parent[v] = u;
            if(u != n) cost[v] = get_minp(v+1,u);
            if(cost[v] >= cost[u]){
                nex[v] = u;
            }
            else{
                int st = u;
                while(1){
                    if(cost[v] >= cost[st]){
                        nex[v] = st;
                        break;
                    }
                    st = nex[st];
                }
            }
            DFS2(v);
        }
    }
}

void Init(){
    FOR(i,1,n-1) w[i] -= gg[i];
    sum[0] = 0;
    FOR(i,1,n) sum[i] = sum[i-1] + w[i];
    p[n] = infi;
    init_rmq();


    /// right of sum - sum[i] < sum[R[i]]
    stack<int> S;
    sum[n] = -Linfi;
    S.push(n);
    FORD(i,n-1,0){
        while(!S.empty() && sum[S.top()] <= sum[i]) S.pop();
        if(!S.empty()) R[i] = S.top();
        else R[i] = n;
        S.push(i);
    }

    /// right of p - p[i] > p[Rp[i]]
    while(!S.empty()) S.pop();
    p[n] = infi; S.push(n); Rp[n] = n;
    FORD(i,n-1,1){
        while(!S.empty() && p[S.top()] >= p[i]) S.pop();
        if(!S.empty()) Rp[i] = S.top();
        else Rp[i] = n;
        S.push(i);
    }
    //FOR(i,0,n-1) cout << sum[i] << " "; cout << endl;
    //FOR(i,0,n-1) cout << R[i] << " "; cout << endl;
    //FOR(i,1,n) cout << p[i] << " "; cout << endl;
    //FOR(i,1,n) cout << Rp[i] << " "; cout << endl;


    FOR(i,0,n-1) adj[R[i]].pb(i);
    memset(xet,0,sizeof(xet));
    memset(cost,0,sizeof(cost));
    cost[n] = 0;
    DFS2(n);
    ///


    ///
    memset(sumdis,0,sizeof(sumdis));
    memset(xet,0,sizeof(xet));
    memset(weight,0,sizeof(weight));
    DFS(n);
    //FORD(i,n-1,0) cout << weight[i] << endl;
    //FORD(i,n-1,0) cout << i << " " << nex[i] << " " << weight[i] << endl;
    //cout << weight[0] << endl;
}

void solve(){

    while(m--){
        cin >> ST >> EN;
        EN--;
        LL maxx = get_max_sum(ST,EN);
        if(maxx <= sum[ST-1] || ST == EN+1){
            cout << "0\n"; continue;
        }
        int low = ST, high = EN, mid, pos = -1;
        while(low <= high){
            mid = (low+high)/2;
            if(get_max_sum(ST,mid) < maxx){
                low = mid+1;
            }
            else{
                pos = mid;
                high = mid-1;
            }
        }
        LL ans;
        int v = ST-1, u = pos, tmp;
        LL min1 = get_minp(v+1,u);
        LL min2 = get_minp(u+1,n);
        if(min1 <= min2){
            ans = weight[v] - sumdis[u]*min1;
            //cout << ST << " " << EN << " " << weight[v] << endl;
        }
        else{
            int z = u;
            while(1){
                if(min1 >= cost[z]) break;
                else z = nex[z];
            }

            //cout << v << " " << u << " " << z << endl;
            ans = weight[v] - weight[z] - (sum[z]-sum[u])*min1;
            //cout << min1  << " " << z << endl;
        }
        //cout << pos << endl;
        //cout << sumdis[pos] << " " << min1 << " " << min2 << endl;
        //

        //cout << min1 << " " << min2 << endl;
        cout << ans << "\n";
    }

}


int main(){
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.inp","w",stdout);
#endif

    cin >> n >> m;
    FOR(i,1,n-1) cin >> w[i];
    FOR(i,1,n) cin >> gg[i] >> p[i];

    Init();
    solve();

    return 0;
}
