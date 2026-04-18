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
ll div(ll n){
    ll ret=0;
    for(int i=1;i*i<=n;i++){
        ret+=(i+n/i)*(n%i==0);
        if(i*i==n) ret-=i;
    }
    return ret;
}
int main() {
  fre("GHH");
  fasteio();
  ll q;
  cin >> q;
  ll cnt=0;
  vector<ll> ans;
  while(q--){
    ll n;
    cin >> n;
    ll sol=div(n);
    if(sol >= 2*n){
         ans.pb(n);
         cnt++;
    }
  }
  cout << cnt << endl;
  for(auto x : ans) cout << x << endl;
  return 0;
}
