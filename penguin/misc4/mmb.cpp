#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define allr(x) x.rbegin(), x.rend();
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
int main() {
  fasteio();
  fre("DAYCONTDN");
  ll n;
  cin >> n;
  vector<ll> a(n+1);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<ll> dp(n+1);
  vector<ll> b(n+1);
  for(int i=0;i<n;i++){
    dp[i] = a[i];
    for(int j=0;j<i;j++){
      if(a[j]<a[i]){
        dp[i] = max(dp[i], dp[j]+a[i]);
        b[i] = max(b[i], b[j]+a[i]);
      }
    }
  }
  return 0;
}
