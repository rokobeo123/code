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
struct Node {
    string u;
    int v, w;
};
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
    ll n, m,k;
    cin >> n >> m >> k;
    set<pair<int,int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        edges.insert({u, v});
    }
    vector<Node> nodes(k);
    set<pair<int,int>> cut;
    for(int i = 0; i < k; i++) {
        cin >> nodes[i].u >> nodes[i].v >> nodes[i].w;
        if(nodes[i].u == "cut") {
            ll u = nodes[i].v;
            ll v = nodes[i].w;
            if(u > v) swap(u, v);
            cut.insert({u, v});
        }
    }
    init(n+1);
    for(auto canh : edges) {
        if(cut.count(canh) == 0) {
            unite(canh.first, canh.second);
        }
    }
    vector<string> ans;
    for(int i=k-1; i>=0; i--) {
        if(nodes[i].u == "ask") {
            ll u = nodes[i].v;
            ll v = nodes[i].w;
            if(find(u) == find(v)) {
                ans.pb("YES");
            } else {
                ans.pb("NO");
            }
        } else {
            ll u = nodes[i].v;
            ll v = nodes[i].w;
            unite(u, v);
        }
    }
    reverse(all(ans));
    for(auto s : ans) {
        cout << s << endl;
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
