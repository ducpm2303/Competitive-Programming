struct matrix{
   ll p[100][100];
};
matrix mulMatrix(matrix a,matrix b){
    matrix res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res.p[i][j] = 0;
            for(int k = 0; k < n; k++){
                res.p[i][j] += (a.p[i][k]*b.p[k][j])%mod;
                res.p[i][j] %= mod;
            }
        }
    }
    return res;
}
matrix fastPow(matrix a, ll b){
    if(b == 1) return a;
    matrix tmp = fastPow(a, b/2);
    tmp = mulMatrix(tmp,tmp);
    if(b%2 == 1)
        return mulMatrix(tmp,a);
    else 
        return tmp;
}