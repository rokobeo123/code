#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unordered_map
#define allr(x) x.rbegin(), x.rend();
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
const ll MOD = 1e9 + 7;
const int A = 1e5 + 1;

int main()
{
  fasteio();
  int n;
  int a[100005];
  int freq[MAXN + 5], uoc[MAXN + 5], f[MAXN + 5], p2[MAXN + 5];
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    freq[a[i]]++;
  }
  for (int u = 1; u <= MAXN; u++)
  {
    for (int j = u; j <= MAXN; j += u)
    {
      uoc[u] += freq[j];
    }
  }
  p2[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    p2[i] = (p2[i - 1] * 2) % MOD;
  }
  for (int u = 1; u <= MAXN; u++)
  {
    f[u] = (p2[uoc[u]] - 1 + MOD) % MOD;
  }
  for (int u = MAXN; u >= 1; u--)
  {
    for (int v = 2 * u; v <= MAXN; v += u)
    {
      f[u] = (f[u] - f[v] + MOD) % MOD;
    }
  }
  cout << f[1] << endl;
  return 0;
}
