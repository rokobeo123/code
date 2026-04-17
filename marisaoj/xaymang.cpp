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
ll dp[1005][1005];
vector<ll> primes;
void sieve() {
    vector<bool> is_prime(2005, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < 2005; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = i * i; j < 2005; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
int main() {
  fasteio();
    ll n,k;
    cin >> n >> k;
    sieve();
    for(int i = 0; i <=k; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int p : primes) {
                if(p-j >= 0 && p-j <= k) {
                    dp[i][j] = (dp[i][j] + dp[i-1][p-j]) % MOD;
                }
            }
        }
    }
    ll res=0;
    for(int i = 0; i <= k; i++) {
        res = (res + dp[n][i]) % MOD;
    }
    cout << res << endl;
  return 0;
}
