
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
const ll MOD = 1e9 + 7;
vector<ll> uoc;
vector<pair<ll,ll>> res;
void uocso(ll n) {
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      uoc.pb(i);
      uoc.pb(-i);
      if (i * i != n) {
        uoc.pb(n / i);
        uoc.pb(-(n / i));
      }
    }
  }
}
void check(ll d, ll n, ll a, ll b, ll c) {
  if(d==0) return;
  if((d-b)%c!=0) return;
    ll x = (d - b) / c;
    if (x < 0) return;
    ll p=n-a*x;
    if(p%d!=0) return;
    ll y=p/d;
    if(y<0) return;
    res.pb({x,y});
}
int main() {
  fasteio();
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    ll so= n*c +a*b;
    uocso(abs(so));
    for(auto i :uoc) check (i,n,a,b,c);
    sort(all(res));
    res.erase(unique(all(res)),res.end());
    cout << res.size() << endl;
    for(auto i : res) cout << i.fi << " " << i.se << endl;
  return 0;
}

