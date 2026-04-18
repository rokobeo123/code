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
const ll MAXN = 1e5 + 5;
ll tree[MAXN * 4];
ll a[MAXN];
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}
void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(node * 2, start, mid, idx, val);
        } else {
            update(node * 2 + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main() {
  fasteio();
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
        while(q--){
            ll type;
            cin >> type;
            if(type == 1) {
                ll idx, val;
                cin >> idx >> val;
                idx--;
                a[idx] = val;
                update(1, 0, n - 1, idx, val);
            } else {
                ll l,r;
                cin >> l >> r;
                l--;r--;
                cout << query(1, 0, n - 1, l, r) << endl;
            }
        }
  return 0;
}
