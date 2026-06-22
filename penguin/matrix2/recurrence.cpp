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
vector<ll> a(100001);
vector<ll> c(100001);
ll MAXN=4294967295;
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
                c.a[i][j] = c.a[i][j] ^ (a.a[i][k] & b.a[k][j]);
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
                c.a[i][j] = (i==j) ? MAXN : 0;
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
  ll k,m;
    cin >> k >> m;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> c[i];
    }
    if(m <= k) {
        cout << a[k-1] << endl;
        return 0;
    }
    matrix A(k);
        for(int i=1;i<k;i++){
            A.a[i][i+1]=MAXN;
        }
        for(int i=1;i<=k;i++){
            A.a[k][i]=c[k-i];
        }
    A = pow(A, m-k);
    ll ans=0;
    for(int i=1;i<=k;i++){
        ans = ans ^ (A.a[k][i] & a[i-1]);
    }
    cout << ans << endl;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
