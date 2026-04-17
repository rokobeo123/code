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
const ll MOD = 1e9 + 7;
const ll INV2 = 500000004;
const int maxn = 1e5 + 5;

struct Node {
  ll sum, l1, l2;
} tree[4 * maxn];

ll mod_norm(ll x) {
  x %= MOD;
  if (x < 0) x += MOD;
  return x;
}

ll sum_index(ll l, ll r) {
  ll len = (r - l + 1) % MOD;
  ll s = (mod_norm(l) + mod_norm(r)) % MOD;
  return s * len % MOD * INV2 % MOD;
}

void build(ll id, ll l, ll r) {
  tree[id].sum = 0;
  tree[id].l1 = 0;
  tree[id].l2 = 0;
  if (l == r) return;
  ll mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
}
void down(ll id, ll l, ll r) {
  if (tree[id].l1 == 0 && tree[id].l2 == 0) return;
  ll mid = (l + r) / 2;
    ll dt = (mid - l + 1) % MOD;
    ll dp = (r - mid) % MOD;
    ll tt = (tree[id].l1 * sum_index(l, mid) + tree[id].l2 * dt) % MOD;
    ll tp = (tree[id].l1 * sum_index(mid + 1, r) + tree[id].l2 * dp) % MOD;
    tree[id * 2].sum = (tree[id * 2].sum + tt) % MOD;
    tree[id * 2 + 1].sum = (tree[id * 2 + 1].sum + tp) % MOD;
    tree[id * 2].l1 = (tree[id * 2].l1 + tree[id].l1) % MOD;
    tree[id * 2].l2 = (tree[id * 2].l2 + tree[id].l2) % MOD;
    tree[id * 2 + 1].l1 = (tree[id * 2 + 1].l1 + tree[id].l1) % MOD;
    tree[id * 2 + 1].l2 = (tree[id * 2 + 1].l2 + tree[id].l2) % MOD;
  tree[id].l1 = 0;
  tree[id].l2 = 0;
}

void update(ll id, ll l, ll r, ll x, ll y, ll a, ll b) {
  if (y < l || x > r) return;
  if (x <= l && r <= y) {
    ll len = (r - l + 1) % MOD;
    ll add = (a * sum_index(l, r) + b * len) % MOD;
    tree[id].sum = (tree[id].sum + add) % MOD;
    tree[id].l1 = (tree[id].l1 + a) % MOD;
    tree[id].l2 = (tree[id].l2 + b) % MOD;
    return;
  }
  ll mid = (l + r) / 2;
  down(id, l, r);
  update(id * 2, l, mid, x, y, a, b);
  update(id * 2 + 1, mid + 1, r, x, y, a, b);
  tree[id].sum = (tree[id * 2].sum + tree[id * 2 + 1].sum) % MOD;
}

ll getv(ll id, ll l, ll r, ll u, ll v) {
  if (v < l || u > r) return 0;
  if (u <= l && r <= v) return tree[id].sum;
  ll mid = (l + r) / 2;
  down(id, l, r);
  ll left = getv(id * 2, l, mid, u, v);
  ll right = getv(id * 2 + 1, mid + 1, r, u, v);
  return (left + right) % MOD;
}

int main() {
  fasteio();

  ll n, m;
  cin >> n >> m;

  build(1, 1, n);
  while (m--) {
    ll type;
    cin >> type;
    if (type == 1) {
      ll l, r, a, b;
      cin >> l >> r >> a >> b;
      ll a = mod_norm(a);
      ll b = mod_norm(b - a * l);
      update(1, 1, n, l, r, a, b);
    } else {
      ll l, r;
      cin >> l >> r;
      cout << getv(1, 1, n, l, r) << endl;
    }
  }

  return 0;
}
