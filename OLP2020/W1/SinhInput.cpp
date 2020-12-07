#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<long long, long long> pt;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long Create(long long l, long long r)
{ //sinh 1 so tu 1 den n
    return rng() % (r - l + 1) + l;
}
//sinh test nho
void createTest(ofstream &fout)
{
    int n = 100, k = 10;
    int m = 5000;
    fout << n << ' ' << k << ' ' << m  << '\n';
    map<int,bool> ok;
    for(int i = 1; i <= k; i++){
        int u = Create(1,100);
        while(ok[u] == true) u = Create(1,100);
        ok[u] = true;
        fout << u << ' ';
    }
    fout << '\n';
    map<pair<int,int>,bool> mark;
    for(int i = 1; i <= m; i++){
        int u = Create(1,100);
        int v = Create(1,100);
        while(mark[{u,v}] == true && mark[{v,u}] == true){
            u = Create(1,100);
            v = Create(1,100);
        }
        mark[{u,v}] = mark[{v,u}] = true;
        //cout << u << ' ' << v << '\n';
        fout << u << ' ' << v << ' ' << Create(1,1e5) << '\n';
    }
}

//cho nay khong can sua
int main()
{
    srand(time(NULL));
    int N = 1;
    for (int i = 0; i < N; i++)
    {
        string input = "test.txt";
        ofstream fout(input.c_str());
        createTest(fout);
        fout.close();
        cout << "Created test:" << i + 1 << endl;
    }
    return 0;
}
