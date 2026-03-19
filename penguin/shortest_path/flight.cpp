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
    vector<vector<pair<ll, ll>>> adj(n + 1);
    ll dist[n + 1][2];
    for(ll i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(mp(v, w));
    }
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    pq.push(mp(0, mp(0, 1)));
    for(ll i = 1; i <= n; i++) {
        dist[i][0] = dist[i][1] = INF;
    }
    dist[1][0] = 0;
    while (!pq.empty()) {
        auto [d, p] = pq.top();
        pq.pop();
        ll ticket = p.fi;
        ll u = p.se;
        if(d > dist[u][ticket]) continue;
        for (auto [v, w] : adj[u]) {
            if(ticket == 0) {
                if(dist[u][0] + w < dist[v][0]) {
                    dist[v][0] = dist[u][0] + w;
                    pq.push(mp(dist[v][0], mp(0, v)));
                }
                if(dist[u][0] + w/2 < dist[v][1]) {
                    dist[v][1] = dist[u][0] + w/2;
                    pq.push(mp(dist[v][1], mp(1, v)));
                }
            } else {
                if(dist[u][1] + w < dist[v][1]) {
                    dist[v][1] = dist[u][1] + w;
                    pq.push(mp(dist[v][1], mp(1, v)));
                }
            }
        }
    }
    if(dist[n][0] == INF && dist[n][1] == INF) {
        cout << -1;
        return 0;
    }
    cout << min(dist[n][0], dist[n][1]);
  return 0;
}
