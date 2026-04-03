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
const ll base = 31;
ll get_hash(const vector<ll> &h, const vector<ll> &pw, ll mod, int l, int r) {
  return (h[r] - h[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}
int main() {
  fasteio();

  string s;
  cin >> s;
  int n = s.size();
  vector<ll> p1(n + 1, 1);
  vector<ll> h1(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    p1[i] = (p1[i - 1] * base) % MOD;
    int x = s[i - 1] - 'a' + 1;
    h1[i] = (h1[i - 1] * base + x) % MOD;
  }
  cout << n;
  for (int i = 2; i <= n; ++i) {
    int lo = 0, hi = n - i + 1, ans = 0;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      ll pref = get_hash(h1, p1, MOD, 1, mid);
      ll sub = get_hash(h1, p1, MOD, i, i + mid - 1);
      if (pref == sub) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    cout << ' ' << ans;
  }
  cout << '\n';

  return 0;
}
