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

int m, n;
vector<string> adj;
vector<vector<bool>> check;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y, char val) {
  check[x][y] = true;
  int area = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !check[nx][ny] && adj[nx][ny] == val) {
      area += dfs(nx, ny, val);
    }
  }
  return area;
}

int main() {
  fre("area01");
  fasteio();
  cin >> m >> n;
  adj.resize(m);
  check.assign(m, vector<bool>(n, false));

  for (int i = 0; i < m; i++) {
    cin >> adj[i];
  }

  int mx = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!check[i][j]) {
        int area = dfs(i, j, adj[i][j]);
        mx = max(mx, area);
      }
    }
  }

  cout << mx << endl;
  return 0;
}
