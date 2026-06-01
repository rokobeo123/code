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
  fre("bfs2");
  fasteio();

  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  vector<int> maxDist(n + 1);
  for (int start = 1; start <= n; start++) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    maxDist[start] = 0;
    for (int i = 1; i <= n; i++) {
      maxDist[start] = max(maxDist[start], dist[i]);
    }
    maxDist[start]++;
  }
  int diameter = 0;
  for (int i = 1; i <= n; i++) {
    diameter = max(diameter, maxDist[i]);
  }

  int minEcc = INT_MAX;
  for (int i = 1; i <= n; i++) {
    minEcc = min(minEcc, maxDist[i]);
  }

  vector<int> centers;
  for (int i = 1; i <= n; i++) {
    if (maxDist[i] == minEcc) {
      centers.pb(i);
    }
  }

  cout << diameter << endl;
  cout << centers.size() << endl;
  for (int i = 0; i < (int)centers.size(); i++) {
    if (i) cout << ' ';
    cout << centers[i];
  }
  cout << endl;

  return 0;
 }
