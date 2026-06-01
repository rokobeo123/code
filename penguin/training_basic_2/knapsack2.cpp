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
  vector<ll> w, v;
  vector<ll> f(m+1, 0);
    w.pb(0); v.pb(0);
    while(n--){
        ll x,y,a;
        cin >> x >> y >> a;
        ll pow1 = 1;
        while(a >= pow1){
            a -= pow1;
            w.pb(x * pow1);
            v.pb(y * pow1);
            pow1 *= 2;
        }
        if(a > 0){
            w.pb(x * a);
            v.pb(y * a);
        }
    }
    n = w.size()-1;
    for(ll i=1;i<=n;i++){
        for(ll j=m;j>=0;j--){
            if(j >= w[i]){
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
    }
    cout << f[m];
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
