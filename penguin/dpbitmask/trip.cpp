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
ll n, dp[1 << 21][25];
ll a[25][25];
ll ison(ll mask, ll i){
    return mask >> i & 1;
}
int main() {
  fasteio();
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int mask =1 ;mask < (1 << n); mask++){
        if(__builtin_popcount(mask) == 1){
            for(int i = 1; i <= n; i++){
                if(mask >> (i-1) & 1){
                    dp[mask][i] = 0;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(ison(mask, i-1)){
                for(int j = 1; j <= n; j++){
                    if(!ison(mask, j-1)){
                        dp[mask | (1 << (j-1))][j]= min(dp[mask | (1 << (j-1))][j], dp[mask][i] + a[i][j]);
                    }
                }
            }
        }
    }
    ll ans = INF;
    for(int i = 1; i <= n; i++){
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << ans << endl;
  return 0;
}
