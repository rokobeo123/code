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
const ll maxn = 1e5 + 5;
vector<ll> adj[maxn];
ll par[maxn];
ll pid=0;
void dfs(ll u, ll p){
    par[u] = p;
    for(auto v : adj[u]){
        if(!par[v]){
            dfs(v, p);
        }
    }
}
int main() {
  fasteio();
  ll n,m,q;
  cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        ll u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(!par[i]){
            dfs(i, ++pid);
        }
    }
    for(int i = 0; i < q; i++){
        ll u,v;
        cin >> u >> v;
        if(par[u] == par[v]) cout << "YES\n";
        else cout << "NO\n";
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
