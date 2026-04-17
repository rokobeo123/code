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
const int maxv = 60000;
ll tree[4 * maxv + 5];

void update(int id, int l, int r, int pos, ll val) {
  if (pos < l || pos > r) return;
  if (l == r) {
    tree[id] += val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) update(id * 2, l, mid, pos, val);
  else update(id * 2 + 1, mid + 1, r, pos, val);
  tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v) {
  if (u > v) return 0;
  if (v < l || r < u) return 0;
  if (u <= l && r <= v) return tree[id];
  int mid = (l + r) / 2;
  return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
  fasteio();

  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ans += get(1, 1, maxv, x + 1, maxv);
    update(1, 1, maxv, x, 1);
  }
  cout << ans << endl;

  return 0;
}
