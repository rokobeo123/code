#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unordered_map
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
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
     vector<vector<ll>> dp(n, vector<ll>(m));
    for (int j = 0; j < m; ++j) {
        dp[0][j] = a[0][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(a[i][j] ==1 ){
                dp[i][j] = dp[i-1][j]+1;
            }
             else{
                dp[i][j] = 0;
            }
        }
    }
     ll ans = 0;
     for (int i = 0; i < n; ++i) {
        stack<ll> st;
        for (int j = 0; j <= m; ++j) {
            ll cur = (j == m ? 0 : dp[i][j]);
            while (!st.empty() && dp[i][st.top()] > cur) {
                ll h = dp[i][st.top()];
                st.pop();
                ll l = st.empty() ? -1 : st.top();
                ll w = j - l - 1;
                ans = max(ans, h * w);
            }
            st.push(j);
        }
     }
    cout << ans;
  return 0;
}
