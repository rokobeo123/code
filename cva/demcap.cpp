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
    fre("BAI3");
  fasteio();
  ll n,s;
  cin >> n >> s;
  ll a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  ll cnt[1000001]={0};
  ll dem=0;
  for(int i=0;i<n;i++){
    ll need=s-a[i];
    if(need>=0&&need<=1000000){
        dem+=cnt[need];
    }
    cnt[a[i]]++;
  }
  cout << dem;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
