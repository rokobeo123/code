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

const ll MAXN = 300005;
const ll INF = 1e9;
const ll MOD = 1e9 +7;
ll bit[MAXN];
ll prf[MAXN];
ll get(int i) {
    ll idx=i;
    ll res=0;
    while(idx>0){
        res+=bit[idx];
        idx-=(idx & -idx);
    }
    return res;
}
void update(int i, ll val) {
    ll idx=i;
    while(idx<MAXN){
        bit[idx]+=val;
        idx+=(idx & -idx);
    }
}
int main() {
    fre("VSEQ");
  fasteio();
  ll n,l,r;
  cin >> n >> l >> r;
  vector<ll> a(n+1);
  for(int i=1; i<=n; i++) cin >> a[i];
    prf[0] = 0;
    for(int i=1; i<=n; i++) prf[i] = prf[i-1] + a[i];
    vector<ll> var;
    for(int i=0; i<=n; i++) {
        var.pb(prf[i]);
        if(i>0){
        var.pb(prf[i]-l);
        var.pb(prf[i]-r);
        }
    }
    sort(all(var));
    var.resize(unique(all(var)) - var.begin());
    ll ans=0;
    update(lower_bound(all(var), prf[0]) - var.begin() + 1, 1);
    for(int i=1; i<=n; i++) {
        ll x = lower_bound(all(var), prf[i]) - var.begin() + 1;
        if(i>0){
            ll y = lower_bound(all(var), prf[i]-l) - var.begin() + 1;
            ll z = lower_bound(all(var), prf[i]-r) - var.begin() + 1;
            ans += get(y) - get(z-1);
        }
        update(x, 1);
    }
    cout << ans << endl;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
