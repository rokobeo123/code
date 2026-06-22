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
  ll a,b;
  cin >> a >> b;
  vector<vector<ll>> dp(a+1, vector<ll>(b+1, INF));
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            for(int k=1; k<i; k++){
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            for(int k=1; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    cout << dp[a][b];
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
