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
vector<int> par, sz;
void init(int n) {
    par.resize(n);
    sz.resize(n);
    for(int i = 0; i < n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}
int find(int u) {
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}
void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}
int main() {
  fasteio();
    ll n,m;
    cin >> n >> m;
    init(n+2);
    for(int i = 0; i < m; i++) {
        char c;
        int u;
        cin >> c >> u;
        if(c == '-'){
            par[u] = find(u+1);
        } else {
            ll ans= find(u);
            if(ans > n) {
                cout << -1 << endl;
            } else {
                cout << ans << endl;
            }
        }
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
