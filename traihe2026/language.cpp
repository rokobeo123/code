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
    fre("language");
  fasteio();
  ll n, c , C;
  cin >> n >> c >> C;
  string s;
  cin >> s;
  vector<ll> dp(n+1, -1);
  dp[0] = 0;
  vector<ll> trace(n+1, -1);
  for(int i=1; i<=n; i++){
    ll minval= INF;
    ll maxval = -INF;
    for(ll j=1;j<= C; j++){
        if(i-j < 0) break;
        ll ch = s[i-j] - 'a';
        minval = min(minval, ch);
        maxval = max(maxval, ch);
        if(j >= c && dp[i-j] != -1){
            ll cur= maxval - minval;
            if(dp[i-j] + cur > dp[i]){
                dp[i] = dp[i-j] + cur;
                trace[i] = i-j;
            }
        }
    }
  }
  if(dp[n] == -1){
    cout << "NO" << endl;
    return 0;
  }
  vector<string> res;
  ll cur = n;
  while(cur > 0){
    res.pb(s.substr(trace[cur], cur - trace[cur]));
    cur = trace[cur];
  }
    reverse(all(res));
    cout << dp[n] << endl;
    cout << res.size() << endl;
    for(auto x: res) cout << x << endl;

  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
