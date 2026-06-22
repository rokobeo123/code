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
const ll INF = 1e9;
const ll MOD = 1e9 +7;
struct matrix {
    vector<vector<ll>> a;
    matrix(int n) {
        a.resize(n+1, vector<ll>(n+1));
    }
};
matrix mul(matrix a, matrix b){
    int n = a.a.size() - 1;
    matrix c(n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            c.a[i][j] = 0;
            for(int k=1; k<=n; k++){
                c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
            }
        }
    }
    return c;
}
matrix pow(matrix a, ll n){
    int m = a.a.size() - 1;
    if(n==0){
        matrix c(m);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                c.a[i][j] = (i==j);
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
    ll n,k;
    cin >> n >> k;
    matrix a(n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a.a[i][j];
        }
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
