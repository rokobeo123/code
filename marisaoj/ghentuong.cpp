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
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(4, 0));
    dp[1][0] = a[0];
    dp[1][2] = b[0];
    for (ll i = 2; i <= n; i++) {
        dp[i][0]= max(dp[i-1][2],dp[i-1][3])+a[i-1];
        dp[i][1]= dp[i-1][0]+a[i-1];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+b[i-1];
        dp[i][3]=dp[i-1][2]+b[i-1];
    }
    cout << max(dp[n][0],max(dp[n][1],max(dp[n][2],dp[n][3]))) << endl;
  return 0;
}
