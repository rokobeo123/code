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
  string s;
  cin >> s;
  vector<vector<ll>> dp(2, vector<ll>(n, 0));
  for (ll i = 2; i <=n; i++) {
    ll cur=i%2;
    ll pre=(i-1)%2;
    for (ll j = 0; j <= n-i; j++) {
      ll k = j + i - 1;
      if(s[j] == s[k]) {
        dp[cur][j] = (i == 2) ? 0 : dp[cur][j + 1];
      } else {
        dp[cur][j] = 1 + min(dp[pre][j], dp[pre][j + 1]);
      }
    }
  }
  cout << dp[n%2][0];
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
