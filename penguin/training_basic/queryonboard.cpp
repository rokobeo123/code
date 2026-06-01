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
  ll n, m, q;
  cin >> n >> m >> q;

  vector<ll> row(n + 1, 0);
  vector<ll> col(m + 1, 0);

  while(q--){
    ll type;
    cin >> type;
    if(type == 1){
      ll r, x;
      cin >> r >> x;
      row[r] += x;
    }
    else if(type == 2){
      ll c, x;
      cin >> c >> x;
      col[c] += x;
    }
    else{
      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      ll maxr = LLONG_MIN;
      for(ll i = x1; i <= x2; i++){
        maxr = max(maxr, row[i]);
      }
      ll maxc = LLONG_MIN;
      for(ll j = y1; j <= y2; j++){
        maxc = max(maxc, col[j]);
      }

      cout << maxr + maxc << endl;
    }
  }
  return 0;
}
