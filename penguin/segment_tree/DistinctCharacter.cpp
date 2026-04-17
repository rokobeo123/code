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
const int MAXN = 1e5 + 5;
int tree[4 * MAXN];
void build(int node, int start, int end, const string &s) {
    if (start == end) {
        tree[node] = 1 << (s[start] - 'a');
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid, s);
        build(2*node+1, mid+1, end, s);
        tree[node] = tree[2*node] | tree[2*node+1];
    }
}
void update(int node, int start, int end, int idx, char val) {
    if (start == end) {
        tree[node] = 1 << (val - 'a');
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2*node, start, mid, idx, val);
        } else {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] | tree[2*node+1];
    }
}
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return p1 | p2;
}
int main() {
  fasteio();
    string s;
    cin >> s;
    ll q;
    cin >> q;
    build(1, 0, s.size()-1, s);
    while(q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll pos;
            char c;
            cin >> pos >> c;
            update(1, 0, s.size()-1, pos-1, c);
        } else {
            ll l, r;
            cin >> l >> r;
            ll res = __builtin_popcount(query(1, 0, s.size()-1, l-1, r-1));
            cout << res << endl;
        }
    }
  return 0;
}
