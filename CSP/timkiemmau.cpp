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
    string s,t;
    cin >> s;
    cin >> t;
    int m = s.size(), n = t.size();
    vector<ll> hs(m + 1), ht(n + 1);
    ll base = 31;
    hs[0] = 0;
    ht[0] = 0;
    for(int i=1;i<=m;i++)
        hs[i] = (hs[i-1]*base + (s[i-1]-'A'+1)) % MOD;

    for(int i=1;i<=n;i++)
        ht[i] = (ht[i-1]*base + (t[i-1]-'A'+1)) % MOD;
    ll pw[n + 1];
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = (pw[i-1] * base) % MOD;
    }
    ll ans=0;
    vector<ll> pos;
    for(int i=1;i+m-1<=n;i++){
        ll h = (ht[i+m-1] - ht[i-1]*pw[m]%MOD + MOD) % MOD;
        if(h == hs[m]){
            ans++;
            pos.push_back(i-1);
        }
    }
    cout << ans << "\n";
    for (ll i : pos) {
        cout << i << " ";
    }
  return 0;
}
