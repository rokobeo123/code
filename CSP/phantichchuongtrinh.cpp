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
  fre("LANG");

  vector<string> instructions;
  string line;

  while (getline(cin, line)) {
    if (!line.empty() && line.back() == '\r') line.pop_back();
    if (!line.empty()) instructions.pb(line);
  }

  int n = instructions.size();
  vector<vector<int>> graph(n);

  for (int i = 0; i < n; ++i) {
    string instr = instructions[i];
    // trim leading/trailing spaces
    instr.erase(0, instr.find_first_not_of(" \t"));
    size_t p = instr.find_last_not_of(" \t");
    if (p != string::npos) instr.erase(p + 1);

    if (instr == "NEXT") {
      if (i + 1 < n) graph[i].pb(i + 1);
    } else {
      // starts with JUMP
      istringstream iss(instr);
      string kw;
      iss >> kw; // JUMP
      int a;
      if (iss >> a) {
        if (a >= 1 && a <= n) graph[i].pb(a - 1);
      }
      string maybe;
      if (iss >> maybe) {
        if (maybe == "OR") {
          int b;
          if (iss >> b) {
            if (b >= 1 && b <= n) graph[i].pb(b - 1);
          }
        }
      }
    }
  }

  vector<char> vis(n, 0);
  if (n > 0) {
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : graph[u]) if (v >= 0 && v < n && !vis[v]) {
        vis[v] = 1; q.push(v);
      }
    }
  }

  vector<int> unreachable;
  for (int i = 0; i < n; ++i) if (!vis[i]) unreachable.pb(i + 1);

  cout << unreachable.size() << '\n';
  for (int x : unreachable) cout << x << '\n';

  return 0;
}
