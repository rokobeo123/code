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
const ll base = 31;
int main() {
  fasteio();
  ll n;
  cin >> n;
  vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    vector<string> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<ll> ha(n), hb(m);
    for (int i = 0; i < n; i++) {
        ll h = 0;
        for (char c : a[i]) {
            h = (h * base + (c - 'a' + 1)) % MOD;
        }
        ha[i] = h;
    }
    for (int i = 0; i < m; i++) {
        ll h = 0;
        for (char c : b[i]) {
            h = (h * base + (c - 'a' + 1)) % MOD;
        }
        hb[i] = h;
    }
    sort(all(ha));
    for (int i = 0; i < m; i++) {
        if (binary_search(all(ha), hb[i])) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
  return 0;
}
