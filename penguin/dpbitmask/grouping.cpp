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
ll n, dp[1 << 25], group[1 << 25];
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
            if(i==j) a[i][j] = 0;
        }
    }
    memset(dp, -0x3f, sizeof(dp));
    for(int mask =1 ;mask < (1 << n); mask++){
        for(int i = 1; i <= n; i++){
            if(ison(mask, i-1)){
                for(int j = i+1; j <= n; j++){
                    if(ison(mask, j-1)){
                        group[mask] += a[i][j];
                    }
                }
            }
        }
    }
    dp[0] = 0;
    for(int mask = 0; mask < (1 << n); mask++){
        ll smask= ((1 << n) - 1) ^ mask;
        for(int submask = smask; submask > 0; submask = (submask - 1) & smask){
            dp[mask | submask] = max(dp[mask | submask], dp[mask] + group[submask]);
        }
    }
    cout << dp[(1 << n) - 1];
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
