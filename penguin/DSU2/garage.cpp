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
int main() {
  fasteio();
    ll n;
    cin >> n;
    init(n+1);
    vector<ll> p(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<ll> ans(n+1);
    for(int i= 1; i <= n; i++){
        ll u = p[i];
        ll v = find(u);
        ans[i] = v;
        par[v] = find(v%n +1);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
