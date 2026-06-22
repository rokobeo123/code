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
vector<ll> adj[1e5+5];
ll tin[1e5+5];
ll tout[1e5+5];
ll depth[1e5+5];
void dfs(ll u, ll p, ll d) {
    tin[u] = ++tin[0];
    depth[u] = d;
    for(auto v: adj[u]) {
        if(v == p) continue;
        dfs(v, u, d+1);
    }
    tout[u] = ++tout[0];
}
void lca
int main() {
  fasteio();
    ll n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        ll u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
