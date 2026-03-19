#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define allr(x) x.rbegin(), x.rend();
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
int main() {
  fasteio();
  fre("QUANMA");
  ll m, n;
  cin >> m >> n;

  vector<vector<ll>> a(m + 1, vector<ll>(n + 1, 0));
  for (ll i = 1; i <= m; i++) {
    for (ll j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
  ll ans = 0;

  for (ll i = 1; i <= m; i++) {
    for (ll j = 1; j <= n; j++) {
      ll best = 0;

      if (i - 1 >= 1 && j - 2 >= 1) best = max(best, dp[i - 1][j - 2]);
      if (i - 1 >= 1 && j + 2 <= n) best = max(best, dp[i - 1][j + 2]);
      if (i - 2 >= 1 && j - 1 >= 1) best = max(best, dp[i - 2][j - 1]);
      if (i - 2 >= 1 && j + 1 <= n) best = max(best, dp[i - 2][j + 1]);

      dp[i][j] = best + a[i][j];
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << '\n';
  return 0;
}
