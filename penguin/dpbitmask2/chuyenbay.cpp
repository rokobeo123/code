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
int am[25];
ll dist[25];
int main() {
  fasteio();
    ll n,m;
    cin >> n >> m;
    int states = 1 << n;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
      am[u] |= (1 << v);
    }
    vector<int> dp(states * n, 0);
    dp[(1 << 0) * n + 0] = 1;
    for(int mask = 1; mask < states; mask += 2){
      int sub = mask;
      while(sub){
        int u = __builtin_ctz(sub);
        sub &= (sub - 1);
            int cur = dp[mask * n + u];
            if(cur == 0) continue;
            int avail = am[u] & ~mask;
            while(avail){
                int v = __builtin_ctz(avail);
                avail &= (avail - 1);
                int &ref = dp[((mask | (1 << v)) * n) + v];
                ref += cur;
                if(ref >= MOD) ref -= MOD;
            }
        }
    }
    cout << dp[((states - 1) * n) + (n - 1)];
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
