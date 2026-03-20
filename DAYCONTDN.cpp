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
  int n;
  cin >> n;
  if (n == 0) {
    cout << 0 << '\n' << 0 << '\n';
    return 0;
  }
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> f(n + 1, 1);
  vector<ll> s(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    s[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[j] < a[i]) {
        int lf = f[j] + 1;
        ll sf = s[j] + a[i];
        if (lf > f[i]) {
          f[i] = lf;
          s[i] = sf;
        } else if (lf == f[i] && sf > s[i]) {
          s[i] = sf;
        }
      }
    }
  }
  int ml = f[1];
  ll ms = s[1];
  for (int i = 2; i <= n; i++) {
    if (f[i] > ml) {
      ml = f[i];
      ms = s[i];
    } else if (f[i] == ml && s[i] > ms) {
      ms = s[i];
    }
  }
  cout << ml << '\n';
  cout << ms << '\n';
  return 0;
}

