#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, k;
int x[100];
int a[100][100];
int sum[100];
bool mark[100];
vector < string > ans;

void process() {
    if (sum[n] == k) {
        string s = "";
        for (int i = 1 ; i <= n; i++) {
            s += (x[i] + '0');
            s += ' ';
        }
        s.pop_back();
        ans.push_back(s);
    }
}

void Try(int i) {
    for (int j = 1 ; j <= n; j++) {
        if (!mark[j]) {
            x[i] = j;
            mark[j] = true;
            sum[i] = sum[i - 1] + a[i][j];
            if (i == n) process();
            else Try(i + 1);
            mark[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; j <= n; j++) {
            cin >> a[i][j];
        }
    }   
    Try(1);
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}