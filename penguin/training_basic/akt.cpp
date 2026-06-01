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
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n+1), c(n+1);
    ll tonga = 0, tongc = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], tonga += a[i];
    for(int i = 1; i <= n; ++i) cin >> c[i], tongc += c[i];
    vector<vector<vector<ll>>> dpmin(n+1, vector<vector<ll>>(l+1, vector<ll>(tonga+1, INF)));
    vector<vector<vector<ll>>> dpmax(n+1, vector<vector<ll>>(l+1, vector<ll>(tonga+1, -INF)));
    dpmin[0][0][0] = 0;
    dpmax[0][0][0] = 0;
    for(int idx = 1; idx <= n; ++idx){
        int ai = a[idx]; ll ci = c[idx];
        for(int k = 0; k <= l; ++k){
            for(int s = 0; s <= tonga; ++s){
                if(dpmin[idx-1][k][s] != INF) dpmin[idx][k][s] = min(dpmin[idx][k][s], dpmin[idx-1][k][s]);
                if(dpmax[idx-1][k][s] != -INF) dpmax[idx][k][s] = max(dpmax[idx][k][s], dpmax[idx-1][k][s]);
                if(k+1 <= l && s + ai <= tonga){
                    if(dpmin[idx-1][k][s] != INF) dpmin[idx][k+1][s+ai] = min(dpmin[idx][k+1][s+ai], dpmin[idx-1][k][s] + ci);
                    if(dpmax[idx-1][k][s] != -INF) dpmax[idx][k+1][s+ai] = max(dpmax[idx][k+1][s+ai], dpmax[idx-1][k][s] + ci);
                }
            }
        }
    }
    double ans = 1e300;
    for(int s = 1; s <= tonga-1; ++s){
        if(dpmin[n][l][s] == INF) continue;
        ll cmin = dpmin[n][l][s];
        ll cmax = dpmax[n][l][s];
        double denom = (double)s * (double)(tonga - s);
        double val1 = (double)cmin * (double)(tongc - cmin) / denom;
        ans = min(ans, val1);
        double val2 = (double)cmax * (double)(tongc - cmax) / denom;
        ans = min(ans, val2);
    }
  return 0;
}
