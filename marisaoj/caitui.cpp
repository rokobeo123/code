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
struct Node {
    ll w, s;
};
int main() {
  fasteio();
  ll n, s;
  cin >> n >> s;
  vector<Node> items(n);
  for (ll i = 0; i < n; i++) {
    cin >> items[i].w >> items[i].s;
  }
    vector<vector<ll>> dp(n+1, vector<ll>(s+1, 0));
    for(ll i=1; i <= n; i++) {
        for (ll j = 0; j <= s; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= items[i-1].w) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-items[i-1].w] + items[i-1].s);
            }
        }
    }
    ll ans = 0;
    for (ll j = 0; j <= s; j++) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << endl;
  return 0;
}
