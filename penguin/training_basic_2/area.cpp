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
struct diem{
    ll x,y;
};
ll area(diem a, diem b, diem c){
    return abs(a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}
int main() {
  fasteio();
  ll n;
  cin >> n;
  vector<diem> a(n);
  for(ll i=0;i<n;i++){
      cin >> a[i].x >> a[i].y;
  }
    ll res = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i == j) continue;
            ll max1 = 0;
            ll max2 = 0;
            for(ll k=0;k<n;k++){
                ll cp = (a[j].x-a[i].x)*(a[k].y-a[i].y) - (a[j].y-a[i].y)*(a[k].x-a[i].x);
                if(cp > 0){
                    max1 = max(max1, area(a[i], a[j], a[k]));
                }
                else if(cp < 0){
                    max2 = max(max2, area(a[i], a[j], a[k]));
                }
            }
            if(max1 > 0 && max2 > 0){
                res = max(res, max1 + max2);
            }
        }
    }
    cout << fixed << setprecision(9) << res/2.0;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
