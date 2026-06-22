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
  ll n,k,p;
  cin >> n >> k >> p;
  ll sum=0;
  vector<ll> a(n+1);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    sum+=a[i];
  }
  ll start= p%n;
  ll socap= k/n;
  ll du= k%n;
  ll ans=socap*sum;
  for (ll i = 0; i < du; i++) {
    ans+=a[(start+i)%n];
  }
  cout << ans%MOD;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
