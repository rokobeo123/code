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
struct point{
    ll x,y;
};
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main() {
  fasteio();
  ll p,k;
  cin >> p >> k;
    vector<point> a(p);
    map<ll,ll> mp;
    for(ll i = 0; i < p; i++){
        cin >> a[i].x >> a[i].y;
    }
    for(ll i = 0; i < p; i++){
        ll g = gcd(a[i].x,a[i].y);
        if(g==0) continue;
        for(ll j = 1; j*j <= g; j++){
            if(g%j==0){
                mp[j]++;
                if(j*j!=g) mp[g/j]++;
            }
        }
    }
    ll ans = 0;
    for(auto i:mp){
        if(i.se>=k) ans++;
    }
    cout << ans;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
