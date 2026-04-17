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
struct ngoac{
    ll o,c,d;
};
vector<ngoac> tree;
ngoac merge(ngoac a, ngoac b){
    ngoac res;
    ll match = min(a.o, b.c);
    res.o = a.o + b.o - match;
    res.c = a.c + b.c - match;
    res.d = a.d + b.d + 2 * match;
    return res;
}
void build(ll id, ll l, ll r, const string &s){
    if(l == r){
        if(s[l] == '(') tree[id] = {1, 0, 0};
        else tree[id] = {0, 1, 0};
        return;
    }
    ll mid = (r + l) / 2;
    build(id * 2, l, mid, s);
    build(id * 2 + 1, mid + 1, r, s);
    tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
}
ngoac query(ll id, ll l, ll r, ll u, ll v){
    if(v < l || u > r) return {0, 0, 0};
    if(u <= l && r <= v) return tree[id];
    ll mid = (r + l) / 2;
    ngoac res1 = query(id * 2, l, mid, u, v);
    ngoac res2 = query(id * 2 + 1, mid + 1, r, u, v);
    return merge(res1, res2);
}
int main() {
  fasteio();
    string s;
    cin >> s;
    ll m;
    cin >> m;
    if (s.empty()) {
        while (m--) {
            ll l, r;
            cin >> l >> r;
            cout << 0 << endl;
        }
        return 0;
    }
    tree.assign(4 * s.size() + 5, {0, 0, 0});
    build(1, 0, s.size() - 1, s);
    while (m--) {
        ll l,r;
        cin >> l >> r;
        l--, r--;
        ngoac res = query(1, 0, s.size() - 1, l, r);
        cout << res.d << endl;
    }
    return 0;
}
