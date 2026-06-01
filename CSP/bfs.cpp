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

int main() {
    fre("bfs1");
  fasteio();
  ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool> visited(n + 1, false);
    vector<ll> parent(n + 1, -1);
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    queue<ll> q;
    q.push(1);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        visited[u] = true;
        for (ll v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    for(ll i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
  return 0;
}
