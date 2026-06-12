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
set<ll> s;

const ll INF = 1e9;
const ll MOD = 1e9 +7;
vector<int> par, sz, nxt;
void init(int n) {
    par.resize(n+1);
    sz.resize(n+1);
    nxt.resize(n+1);
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        nxt[i] = i;
        sz[i] = 1;
        s.insert(i);
    }

}
int find(int u) {
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}
int findnxt(int u) {
    if(nxt[u] == u) return u;
    return nxt[u] = findnxt(nxt[u]);
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
  ll n,q;
    cin >> n >> q;
    init(n);
    for(int i = 0; i < q; i++) {
        ll type, u, v;
        cin >> type >> u >> v;
        if(type == 1) {
            unite(u, v);
        } else if(type == 2){
            for(int i = findnxt(u); i < v; i = findnxt(i)) {
                unite(i, i+1);
                nxt[i] = findnxt(i+1);
            }
        }
        else {
            if(find(u) == find(v)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
