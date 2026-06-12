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
  ll n;
  cin >> n;
  vector<ll> a(n+1);
  vector<ll> pos(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    set<ll> s;
    s.insert(0);
    s.insert(-1);
    s.insert(n+1);
    s.insert(n+2);
    ll cnt = 0;
    for(int i=n;i>=1;i--){
        auto it = s.lower_bound(pos[i]);
        ll r1=*it;
        auto it2 = it;
        it2++;
        ll r2=*it2;
        auto it3 = it;
        it3--;
        ll l1=*it3;
        auto it4 = it3;
        it4--;
        ll l2=*it4;
        ll x=0;
        if(l1 != 0){
            x+=(l1-l2)*(r1-pos[i]);
        }
        if(r1 != n+1){
            x+=(r2-r1)*(pos[i]-l1);
        }
        cnt+=x*i;
        s.insert(pos[i]);
    }
    cout << cnt;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
