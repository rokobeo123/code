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

int main()
{
  fasteio();
  fre("LUYENTAP");

  int n, m;
  cin >> n >> m;

  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  sort(all(b));

  vector<ll> pre(m + 1, 0);
  for (int i = 0; i < m; i++)
    pre[i + 1] = pre[i] + b[i];

  for (int i = 0; i < n; i++)
  {
    ll s = a[i];
    while (true)
    {
      int pos = upper_bound(all(b), s) - b.begin();
      ll ns = a[i] + pre[pos];
      if (ns == s)
        break;
      s = ns;
    }
    cout << s;
    if (i < n - 1)
      cout << " ";
  }
  cout << endl;

  return 0;
}
