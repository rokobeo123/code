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
  vector<ll> xs(n), ys(n);
  for (ll i = 0; i < n; i++) cin >> xs[i] >> ys[i];
  ll xmin = xs[0], xmax = xs[0], ymin = ys[0], ymax = ys[0];
  for (ll i = 1; i < n; i++) {
    xmin = min(xmin, xs[i]);
    ymin = min(ymin, ys[i]);
    ymax = max(ymax, ys[i]);
    xmax = max(xmax, xs[i]);
  }
  ll ans= INF, bestx = xmin, besty = ymin;
  for (ll x = xmin; x <= xmax; x++) {
    for (ll y = ymin; y <= ymax; y++) {
      ll ton = 0;
      for (ll i = 0; i < n; ++i) {
        ton += abs(xs[i] - x) + abs(ys[i] - y);
      }
      if (ton < ans) {
        ans = ton;
        bestx = x;
        besty = y;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
