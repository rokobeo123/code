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
ll tree[4 * maxn];
void build(ll id, ll l, ll r){
    if(l == r){
        tree[id] = a[l];
        return;
    }
    ll mid = (r + l) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
void update(ll id,ll l,ll r,ll pos, ll val){
    if(l == r){
        tree[id] = val;
        return;
    }
    ll mid = (r + l) / 2;
    if(l <= pos && pos <= mid) update(id * 2, l, mid, pos, val);
    else update(id * 2 + 1, mid + 1, r, pos, val);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
ll query(ll id, ll l, ll r, ll u, ll v){
    if(v < l || u > r) return 0;
    if(u <= l && r <= v) return tree[id];
    ll mid = (r + l) / 2;
    ll res1 = query(id * 2, l, mid, u, v);
    ll res2 = query(id * 2 + 1, mid + 1, r, u, v);
    return res1 + res2;
}
int main() {
  fasteio();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 0){
            ll u,v;
            cin >> u >> v;
            swap(a[u], a[v]);
            update(1, 1, n, u, a[u]);
            update(1, 1, n, v, a[v]);
        }
        else{
            ll u,v;
            cin >> u >> v;
            cout << query(1, 1, n, u, v) << endl;
        }
    }
  return 0;
}
