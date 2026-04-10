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

  string s;
  if (!(cin >> s)) return 0;

  int n = s.size();
  vector<int> d1(n), d2(n);

  int l = 0, r = -1;
  for (int i = 0; i < n; ++i) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      ++k;
    }
    d1[i] = k;
    if (i + k - 1 > r) {
      l = i - k + 1;
      r = i + k - 1;
    }
  }

  l = 0;
  r = -1;
  for (int i = 0; i < n; ++i) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      ++k;
    }
    d2[i] = k;
    if (i + k - 1 > r) {
      l = i - k;
      r = i + k - 1;
    }
  }

  int maxl = 1;
  int best_l = 0;

  for (int i = 0; i < n; ++i) {
    int len = 2 * d1[i] - 1;
    int st = i - d1[i] + 1;
    if (len > maxl || (len == maxl && st < best_l)) {
      maxl = len;
      best_l = st;
    }
  }

  for (int i = 0; i < n; ++i) {
    int len = 2 * d2[i];
    int st = i - d2[i];
    if (len > maxl || (len == maxl && st < best_l)) {
      maxl = len;
      best_l = st;
    }
  }

  cout << s.substr(best_l, maxl);

  return 0;
}
