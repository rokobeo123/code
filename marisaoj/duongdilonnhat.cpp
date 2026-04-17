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

int main() {
  fasteio();
    ll n;
    cin >> n;
    ll a[n+1][n+1];
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    dp[1][1] = a[1][1];
    for (ll i = 2; i <= n; i++) {
        dp[i][1] = dp[i-1][1] + a[i][1];
        dp[1][i] = dp[1][i-1] + a[1][i];
    }
    for(ll i = 2; i <= n; i++) {
        for (ll j = 2; j <= n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    }
    cout << dp[n][n] << endl;

  return 0;
}
