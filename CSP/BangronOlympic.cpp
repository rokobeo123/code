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
  cin >> s;

  int n = (int)s.size();
  ll total = 1LL * n * (n + 1) / 2;

  ll not_beautiful = 0;
  int cnt[3] = {0, 0, 0};
  int l = 0;

  auto id = [&](char c) {
    if (c == 'O') return 0;
    if (c == 'L') return 1;
    return 2;
  };

  for (int r = 0; r < n; r++) {
    cnt[id(s[r])]++;

    while (cnt[0] > 2 || cnt[1] > 2 || cnt[2] > 2) {
      cnt[id(s[l])]--;
      l++;
    }

    not_beautiful += (r - l + 1);
  }

  cout << total - not_beautiful;
  return 0;
}
