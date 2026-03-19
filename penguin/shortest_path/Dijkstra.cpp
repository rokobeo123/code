#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define allr(x) x.rbegin(), x.rend();
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
const ll INF = 1e15;

int main() {
  fasteio();
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<ll> dist(n + 1, INF);
    vector<int> trace(n + 1, -1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
        adj[v].pb(mp(u, w));
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[1] = 0;
    pq.push(mp(0, 1));
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                trace[v] = u;
                pq.push(mp(dist[v], v));
            }
        }
    }
    ll node=n;
    vector<ll> path;
    if (dist[n] == INF) {
        cout << -1;
        return 0;
    }
    while(node!=1) {
        path.pb(node);
        node=trace[node];
    }
    path.pb(1);
    reverse(all(path));
    for (ll x : path) {
        cout << x << " ";
    }
    return 0;
}
