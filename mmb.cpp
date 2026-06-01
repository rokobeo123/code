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
  if(n==0){
      cout << 0 << endl;
      return 0;
  }
  ll minn=LLONG_MAX;
  ll x = abs(n);
  for(int i=1; i <= x/i;i++){
    if(x%i==0){
        ll j = x/i;
        if(n >= 0) minn =min(minn, abs(i-j));
        else minn = min(minn, j+i);
    }
  }
    cout << minn << endl;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
