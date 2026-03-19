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
  fre("XAUCHUNGNN");
  string s1, s2;
  cin >> s1 >> s2;

  int n = (int)s1.size();
  int m = (int)s2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (s1[i] == s2[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 1;
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  vector<int> ord;
  for (int c = '0'; c <= '9'; c++) ord.push_back(c);
  for (int c = 'A'; c <= 'Z'; c++) ord.push_back(c);
  for (int c = 'a'; c <= 'z'; c++) ord.push_back(c);
  vector<vector<int>> nx1(n + 1, vector<int>(256, -1));
  vector<vector<int>> nx2(m + 1, vector<int>(256, -1));
  for (int i = n - 1; i >= 0; i--) {
    nx1[i] = nx1[i + 1];
    int c1 = (int)s1[i];
    if (c1 < 0) c1 += 256;
    nx1[i][c1] = i;
  }
  for (int j = m - 1; j >= 0; j--) {
    nx2[j] = nx2[j + 1];
    int c2 = (int)s2[j];
    if (c2 < 0) c2 += 256;
    nx2[j][c2] = j;
  }

  int i = 0, j = 0, len = dp[0][0];
  string ans;
  ans.reserve(len);

  while (len > 0) {
    for (int c : ord) {
      int p = nx1[i][c];
      int q = nx2[j][c];
      if (p == -1 || q == -1) continue;
      if (dp[p + 1][q + 1] == len - 1) {
        ans.push_back((char)c);
        i = p + 1;
        j = q + 1;
        len--;
        break;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
