#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unordered_map
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ford(i, a, b) for (int i = int(a); i >= int(b); i--)
#define allr(x) x.rbegin(), x.rend()
#define fasteio()              \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);            \
  cout.tie(nullptr);
void fre(const char *tenbai)
{
  string input_file = string(tenbai) + ".INP";
  string output_file = string(tenbai) + ".OUT";
  freopen(input_file.c_str(), "r", stdin);
  freopen(output_file.c_str(), "w", stdout);
}
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

int main()
{
  fasteio();
  int n, k;
  cin >> n >> k;

  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += a[i];
  }

  vector<ll> s;
  s.reserve(n - 1);
  ll cur = 0;
  for (int i = n; i >= 1; i--)
  {
    cur += a[i];
    if (i >= 2)
      s.push_back(cur);
  }

  sort(s.begin(), s.end(), greater<ll>());
  for (int i = 0; i < k - 1; i++)
  {
    ans += s[i];
  }

  cout << ans;
  return 0;
}
