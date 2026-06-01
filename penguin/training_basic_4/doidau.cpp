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
    vector<pair<ll, ll>> dp(2);
    dp[0]={0,s[0]=='<'?0:-1};
    dp[1]={0,s[0]=='>'?0:-1};
    for(int i=1;i<n;i++){
        vector<pair<ll, ll>> newdp(2);
        ll val = s[i]=='<'?0:-1;
        pair<ll, ll> l= {dp[0].fi, val+dp[0].se};
        pair<ll, ll> r= {dp[1].fi+1, val+dp[1].se};
        newdp[0] = max(l, r);
        ll val2 = s[i]=='>'?0:-1;
        pair<ll,ll> lr = {dp[0].fi, val2+dp[0].se};
        pair<ll,ll> rr = {dp[1].fi, val2+dp[1].se};
        newdp[1] = max(lr, rr);
        dp = newdp;
    }
    pair<ll, ll> res = max(dp[0], dp[1]);
    cout << res.fi << " " << -res.se;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
