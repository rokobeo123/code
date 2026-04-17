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
const int maxn = 1e5 + 5;
ll a[maxn];
struct Node{
    ll sum;
    ll l;
    ll r;
    ll ans;
} tree[4 * maxn];
void build(ll id, ll l, ll r){
    if(l == r){
        tree[id].sum = a[l];
        tree[id].l = a[l];
        tree[id].r = a[l];
        tree[id].ans = a[l];
        return;
    }
    ll mid = (r + l) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id].sum = tree[id *  2].sum + tree[id * 2 + 1].sum;
    tree[id].l = max(tree[id * 2].l, tree[id * 2].sum + tree[id * 2 + 1].l);
    tree[id].r = max(tree[id * 2 + 1].r, tree[id * 2 + 1].sum + tree[id * 2].r);
    tree[id].ans = max({tree[id * 2].ans, tree[id * 2 + 1].ans, tree[id * 2].r + tree[id * 2 + 1].l});
}
Node get(ll id, ll l, ll r, ll u, ll v){
    if(v < l || u > r) return { -INF, -INF, -INF, -INF };
    if(u <= l && r <= v) return tree[id];
    ll mid = (r + l) / 2;
    Node res1 = get(id * 2, l, mid, u, v);
    Node res2 = get(id * 2 + 1, mid + 1, r, u, v);
    ll sum = res1.sum + res2.sum;
    ll sum2 = max(res1.l, res1.sum + res2.l);
    ll sum3 = max(res2.r, res2.sum + res1.r);
    ll sum4 = max({res1.ans, res2.ans, res1.r + res2.l});
    return {sum, sum2, sum3, sum4};
}
int main() {
  fasteio();
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while(q--){
        ll u, v;
        cin >> u >> v;
        Node res = get(1, 1, n, u, v);
        cout << res.ans << endl;
    }
  return 0;
}
