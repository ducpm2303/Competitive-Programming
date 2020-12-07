struct dsu{
    vector < int > par,rank;
    int n;
    dsu(int m){n = m; par.resize(n+1) ; rank.resize(n+1);};
    void in(){
        for(int i = 1 ; i <= n ; i++)
            par[i] = i , rank[i] = 0;
    }
    int find(int u){
        if(par[u] != u) par[u] = find(par[u]);
        return par[u]; 
    }
    void join(int u , int v){
        u = find(u);
        v = find(v);
        if( u == v ) return;
        if ( rank[u] == rank[v]) rank[u]++;
        if ( rank[u] > rank[v]) par[v] = u;
        else par[u] = v;
    }
};