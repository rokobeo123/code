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
const ll BASE = 31;
ll get_hash(const vector<ll> &h, const vector<ll> &pw, ll mod, int l, int r) {
  return (h[r] - h[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}
bool ok(int len) {
  unordered_set<ll> s;
  for (int col = 1; col <= n; ++col) {
    for (int row = len; row <= m; ++row) {
      ll h = get_hash(h1[col], pw1, MOD1, row - len + 1, row);
      if (s.count(h)) {
        return true;
      }
      s.insert(h);
    }
  }
  return false;
}
int main() {
  fasteio();
  int m, n;
  cin >> m >> n;
  vector<string> a(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  vector<ll> pw1(m + 1, 1), pw2(m + 1, 1);
  for (int i = 1; i <= m; ++i) {
    pw1[i] = (pw1[i - 1] * BASE) % MOD1;
  }
  vector<vector<ll>> h1(n + 1, vector<ll>(m + 1, 0));
  for (int col = 1; col <= n; ++col) {
    for (int row = 1; row <= m; ++row) {
      int x = a[row][col] - 'a' + 1;
      h1[col][row] = (h1[col][row - 1] * BASE + x) % MOD1;
    }
  }
  int lo = 0, hi = m - 1, ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (ok(mid)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  cout << ans << '\n';

  return 0;
}
