#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unordered_map
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
  fasteio();
  ll n;
  cin >> n;
  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> dist[i][j];
    }
  }
  vector<ll> order(n);
  for (int i = 0; i < n; i++) {
    cin >> order[i];
  }
  reverse(order.begin(), order.end());
  vector<ll> res;
  set<int> d;
  for (int idx = 0; idx < n; idx++) {
    int k = order[idx];
    d.insert(k);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
    ll sum = 0;
    for (int u : d) {
      for (int v : d) {
        if (u != v) {
          sum += dist[u][v];
        }
      }
    }

    res.push_back(sum);
  }
  reverse(res.begin(), res.end());

  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }

  return 0;
}
