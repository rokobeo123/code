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
  int m, n;
  ll k;
  cin >> m >> n >> k;
  if (k != m) {
    cout << 0 << '\n';
    return 0;
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(m, 0));
  dp[0][0] = 1;
  for (int col = 0; col < n; col++) {
    for (int r = 0; r < m; r++) {
      if (dp[col][r] == 0) continue;
      ll b = dp[col][r];
      if (r == 0) {
        dp[col + 1][0] = (dp[col + 1][0] + b) % MOD;
      }
      dp[col + 1][(r + 1) % m] = (dp[col + 1][(r + 1) % m] + b) % MOD;
    }
  }

  cout << dp[n][0] << '\n';
  return 0;
}
