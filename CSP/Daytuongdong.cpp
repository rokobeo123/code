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
const ll HASH_MOD = 4000000007LL;
const ll SHIFT = 1000000000LL;

ll mul_mod(ll a, ll b) {
  return (ll)((__int128)a * b % HASH_MOD);
}

bool check(int len, const vector<ll> &h1, const vector<ll> &p1, int m) {
  if (len == 0) return true;
  unordered_set<ll> seen;
  seen.reserve((size_t)max(1, m - len + 1) * 2);
  for (int l = 0; l + len <= m; ++l) {
    int r = l + len;

    ll key = (h1[r] - mul_mod(h1[l], p1[len]) + HASH_MOD) % HASH_MOD;

    if (seen.find(key) != seen.end()) return true;
    seen.insert(key);
  }

  return false;
}

int main() {
  fasteio();

  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    if (n <= 1) {
      cout << 0 << '\n';
      continue;
    }

    int m = n - 1;
    vector<ll> d(m);
    for (int i = 0; i < m; ++i) {
      d[i] = a[i + 1] - a[i];
    }

    vector<ll> h1(m + 1, 0);
    vector<ll> p1(m + 1, 1);

    for (int i = 1; i <= m; ++i) {
      p1[i] = mul_mod(p1[i - 1], BASE);
    }

    for (int i = 0; i < m; ++i) {
      ll v = d[i] + SHIFT;
      h1[i + 1] = (mul_mod(h1[i], BASE) + v) % HASH_MOD;
    }

    int lo = 1, hi = m, best = 0;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (check(mid, h1, p1, m)) {
        best = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    cout << (best + 1) << '\n';
  }
  return 0;
}
