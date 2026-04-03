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
ll get_hash(const vector<ll> &h, const vector<ll> &pw, ll mod, int l, int r) {
  return (h[r] - h[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}
int main() {
  fasteio();
  int n;
  cin >> n;
  string s;
  cin >> s;
  const ll BASE = 31;
  string rs = s;
  reverse(rs.begin(), rs.end());

  vector<ll> pw1(n + 1, 1);
  vector<ll> h1(n + 1, 0);
  vector<ll> rh1(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    pw1[i] = (pw1[i - 1] * BASE) % MOD;
    h1[i] = (h1[i - 1] * BASE + (s[i - 1] - 'a' + 1)) % MOD;
    rh1[i] = (rh1[i - 1] * BASE + (rs[i - 1] - 'a' + 1)) % MOD;
  }
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int rl = n - r + 1;
    int rr = n - l + 1;
    ll hf1 = get_hash(h1, pw1, MOD, l, r);
    ll hr1 = get_hash(rh1, pw1, MOD, rl, rr);
    cout << ((hf1 == hr1) ? "YES" : "NO") << '\n';
  }

  return 0;
}
