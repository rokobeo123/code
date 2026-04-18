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
  fre("work");
  ll n;
  cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<ll> b(n-1);
    for(int i=0;i<n-1;i++) cin >> b[i];
    vector<ll> dp(n);
    dp[0] = a[0];
    dp[1] = min(a[0]+a[1], b[0]);
    for(int i=2;i<n;i++){
        dp[i] = min(dp[i-1]+a[i], dp[i-2]+b[i-1]);
    }
    cout << dp[n-1] << endl;
  return 0;
}
