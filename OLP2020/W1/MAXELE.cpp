/*author : mdp*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


class SegmentTree{
private :
    vector <ll> Tree;
    vector <ll> p;
public :
    ll merge(ll a , ll b){ return max(a,b);}
    void build(int node , int l , int r){
		if ( l == r ){
			Tree[node] = p[l-1];
			return;
		}
		int mid = l + r >> 1;
		build(node*2,l,mid);
		build(node*2+1,mid+1,r);
		Tree[node] = merge(Tree[node*2],Tree[node*2+1]);
	}
    ll get(int node , int l , int r , int x , int y){
		if ( l > y || r < x) return 0;
		if ( x <= l && r <= y ) return Tree[node];
		int mid = l + r >> 1;
		ll a = get(node*2,l,mid,x,y);
		ll b = get(node*2+1,mid+1,r,x,y);
		return merge(a,b);
	}
    SegmentTree ( vector<ll> p){
        int sz = p.size();
        Tree.assign(4*sz+5,0) ;
        this->p = p;
    }
};
ll n,m,x,y;
vector<ll> a;
void Input(){
    cin >> n;
    a.resize(n);
    for(auto &z : a)
        cin >> z;
    cin >> m >> x >> y;
}

void Solve(){
    SegmentTree ST(a);
    ST.build(1,1,n);
    map<pair<int,int>,ll> S;
    ll u = x, v = y, c = 0, stop = -1;
    ll sum = 0;
    for(ll i = 1; i <= m; i++){
        if(x == u && y == v){
            c++;
            if(c == 2){
                stop = i - 1;
                break;
            }
        }
        //cout << x << ' ' << y << '\n';
        int l = min(x+1,y+1) , r = max(x+1,y+1);
        if(S[{l,r}] == 0)
            S[{l,r}] = ST.get(1,1,n,l,r);
        sum += S[{l,r}];
        x = (x+7)%(n-1);
        y = (y+11)%n;
    }
    if(stop == -1){
        cout << sum;
    }else{
        //cout << stop << '\n';
        ll z = m/stop;
        ll t = m%stop;
        sum = sum*z;
        for(ll i = 1; i <= t; i++){
            int l = min(x+1,y+1) , r = max(x+1,y+1);
            sum += S[{l,r}];
            x = (x+7)%(n-1);
            y = (y+11)%n;
        }
        cout << sum;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        Input();
        Solve();
    }
    return 0;
}