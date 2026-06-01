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
ll n,k;
ll dp[1 << 15][16];
ll solve(ll mask, ll last){
    if(mask == (1 << n) - 1) return 1;
    if(dp[mask][last] != -1) return dp[mask][last];
    ll cnt =0;
    for(int i = 0; i < n; i++){
        if(!(mask & (1 << i ))){
            if(last ==0 || abs(i + 1  - last) <= k){
                cnt += solve(mask | (1 << i), i+1);
            }
        }
    }
    return dp[mask][last] = cnt;
}
int main() {
  fasteio();
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) << endl;
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
