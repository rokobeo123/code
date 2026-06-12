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
ll powmod(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while(b > 0) {
        if(b%2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
ll inv(ll a) {
    return powmod(a, MOD - 2);
}
int main() {
  fasteio();
    ll n;
    cin >> n;
    ll sum=1;
    for(int i = 1; i <= n; i++) {
        ll p,k;
        cin >> p >> k;
        ll tu = powmod(p, k + 1) - 1;
        if(tu < 0) tu += MOD;
        ll mau = p - 1;
        sum = (sum * tu) % MOD;
        sum = (sum * inv(mau)) % MOD;
    }
    cout << sum;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
