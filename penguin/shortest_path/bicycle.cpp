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
  ll t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 1; i <= m; i++) {
      ll u, v, w;
      cin >> u >> v >> w;
      adj[u].pb(mp(v, w));
      adj[v].pb(mp(u, w));
    }

    vector<int> s(n + 1);
    for (ll i = 1; i <= n; i++)
      cin >> s[i];
    vector<vector<ll>> dist(n + 1, vector<ll>(1001, INF));
    using mmb = tuple<ll, int, int>;
    priority_queue<mmb, vector<mmb>, greater<mmb>> pq;

    dist[1][s[1]] = 0;
    pq.push({0, 1, s[1]});

    while (!pq.empty()) {
      auto [d, u, best] = pq.top();
      pq.pop();

      if (d != dist[u][best])
        continue;

      for (auto [v, w] : adj[u]) {
        int nb = min(best, s[v]);
        ll nd = d + w * 1LL * best;

        if (nd < dist[v][nb]) {
          dist[v][nb] = nd;
          pq.push({nd, (int)v, nb});
        }
      }
    }

    ll ans = INF;
    for (int best = 1; best <= 1000; best++)
      ans = min(ans, dist[n][best]);

    cout << ans << '\n';
  }
}
