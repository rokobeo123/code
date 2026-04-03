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

string s, t;
int n;
vector<ll> p1, h1;

ll get_hash(const vector<ll> &h, const vector<ll> &pw, ll mod, int l, int r) {
  return (h[r] - h[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}

int lcp(int i, int j) {
  int lo = 0, hi = n, ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (get_hash(h1, p1, MOD, i, i + mid - 1) == get_hash(h1, p1, MOD, j, j + mid - 1)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ans;
}
int main() {
  fasteio();

  cin >> s;
  n = (int)s.size();
  t = s + s;
  p1.assign(2 * n + 1, 1);
  h1.assign(2 * n + 1, 0);

  for (int i = 1; i <= 2 * n; ++i) {
    int x = t[i - 1] - 'a' + 1;
    p1[i] = (p1[i - 1] * BASE) % MOD;
    h1[i] = (h1[i - 1] * BASE + x) % MOD;
  }
  int best = 1;
  for (int st = 2; st <= n; ++st) {
    int cm = lcp(best, st);
    if (cm == n) continue;
    if (t[st + cm - 1] < t[best + cm - 1]) {
      best = st;
    }
  }
  cout << t.substr(best - 1, n) << '\n';
  return 0;
}
