#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unordered_map
#define endl '\n'
#define allr(x) x.rbegin(), x.rend()
#define fasteio()                                                              \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);                                                            \
  cout.tie(nullptr);
void fre(const char *tenbai) {
  string input_file = string(tenbai) + ".INP";
  string output_file = string(tenbai) + ".OUT";
  freopen(input_file.c_str(), "r", stdin);
  freopen(output_file.c_str(), "w", stdout);
}
const ll INF = 4e18;
const ll MOD = 1e9 +7;
struct matrix {
    vector<vector<ll>> a;
    matrix(int n) {
        a.resize(n, vector<ll>(n, INF));
    }
};
matrix mul(matrix a, matrix b){
    int n = a.a.size();
    matrix c(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            c.a[i][j] = INF;
            for(int k=0; k<n; k++){
                if(a.a[i][k] == INF || b.a[k][j] == INF) continue;
                c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
            }
        }
    }
    return c;
}
matrix pow(matrix a, ll n){
    int m = a.a.size();
    if(n==0){
        matrix c(m);
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                if(i == j) c.a[i][j] = 0;
                else c.a[i][j] = INF;
            }
        }
        return c;
    }
    if(n == 1) return a;
    matrix c = pow(a, n/2);
    c = mul(c, c);
    if(n % 2) c = mul(c, a);
    return c;
}
int main() {
  fasteio();
  ll n,m,k;
  cin >> n >> m >> k;
    matrix adj(n);
    for(int i = 0; i < m; i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        adj.a[u][v] = min(adj.a[u][v], w);
    }
    adj = pow(adj, k);
    if(adj.a[0][n-1] == INF) {
        cout << -1 << endl;
    } else {
        cout << adj.a[0][n-1] << endl;
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
