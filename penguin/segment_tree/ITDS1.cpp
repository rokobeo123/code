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
multiset<ll> tree[4 * maxn];
void build(ll id, ll l, ll r){
    if(l == r){
        tree[id].insert(a[l]);
        return;
    }
    if(l == r) return;
    ll mid = (r + l) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    for(auto x: tree[id * 2]) tree[id].insert(x);
    for(auto x: tree[id * 2 + 1]) tree[id].insert(x);
}
void update(ll id,ll l,ll r,ll pos, ll val){
    auto it=tree[id].find(a[pos]);
    if(it != tree[id].end()) tree[id].erase(it);
    tree[id].insert(val);
    if(l==r) return;
    ll mid = (r + l) / 2;
    if(l <= pos && pos <= mid) update(id * 2, l, mid, pos, val);
    else update(id * 2 + 1, mid + 1, r, pos, val);
}
ll query(ll id, ll l, ll r, ll u, ll v, ll k){
    if(v < l || u > r) return INF;
    if(u <= l && r <= v){
        auto it = tree[id].lower_bound(k);
        if(it == tree[id].end()) return INF;
        return *it;
    }
    ll mid = (r + l) / 2;
    ll res1 = query(id * 2, l, mid, u, v, k);
    ll res2 = query(id * 2 + 1, mid + 1, r, u, v, k);
    return min(res1, res2);
}
int main() {
  fasteio();
    ll n,q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--){
        ll type;
        cin >> type;
        if(type == 1){
            ll pos, val;
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
        else{
            ll l,r,k;
            cin >> l >> r >> k;
            ll res = query(1, 1, n, l, r, k);
            if(res == INF) cout << -1 << endl;
            else cout << res << endl;

        }
    }

  return 0;
}
