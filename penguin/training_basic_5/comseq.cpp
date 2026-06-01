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
  ll n,m;
    cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(m);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int j=1;j<=m;j++){
        dp[0][j] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
            }
            else{
                dp[i][j] = (dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%MOD;
            }
        }
    }
    cout << dp[n][m]%MOD;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
