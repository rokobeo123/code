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
const ll MAXN = 2e5 + 5;
ll tree[MAXN * 4];
ll a[MAXN];
vector<ll> cord;
void update(int node, int start, int end, int idx, ll val) {
    if (start == end) {
        tree[node]+= val;
        tree[node]%=MOD;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(node * 2, start, mid, idx, val);
        } else {
            update(node * 2 + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
        tree[node]%=MOD;
    }
}
ll query(int node, int start, int end, ll l,ll r){
    if(r < start || end < l) {
        return 0;
    }
    if(l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    ll left = query(node * 2, start, mid, l, r);
    ll right = query(node * 2 + 1, mid + 1, end, l, r);
    return (left + right) % MOD;
}
int main() {
  fasteio();
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cord.pb(a[i]);
    }
    ll m = cord.size();
    sort(all(cord));
    cord.erase(unique(all(cord)), cord.end());
    ll res = 0;
    for(int i = 0; i < n; i++) {
        int idx = lower_bound(all(cord), a[i]) - cord.begin();
        ll cnt= query(1, 0, m - 1, 0, idx - 1);
        update(1, 0, m - 1, idx, cnt + 1);
    }
    cout << query(1, 0, m - 1, 0, m - 1) << endl;
  return 0;
}
