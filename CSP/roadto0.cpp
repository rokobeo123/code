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
  fasteio();
  ll n;
  cin >> n;
  vector<ll> adj;
  vector<char> check(n + 1, false);
  queue<ll> q;
  check[n] = true;
  q.push(n);

  while (!q.empty()) {
    ll cur = q.front();
    q.pop();

    for (ll d = 1; d * d <= cur; ++d) {
      if (cur % d != 0) continue;
      ll x = d;
      ll y = cur / d;
      ll nxt = (x - 1) * (y + 1);
      if (!check[nxt]) {
        check[nxt] = true;
        adj.pb(nxt);
        if (nxt > 0) q.push(nxt);
      }
    }
  }

  sort(all(adj));
  cout << adj.size() << endl;
  for (size_t i = 0; i < adj.size(); ++i) {
    if (i % 10 == 0 && i) cout << endl;
    if (i % 10) cout << ' ';
    cout << adj[i];
  }
  if (!adj.empty()) cout << endl;

  return 0;
}
