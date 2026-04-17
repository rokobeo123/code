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
    ll m,n;
    cin >> m >> n;
    vector<vector<char>> a(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> h(m, vector<ll>(n, 0));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if(a[i][j] == 'W') {
                h[i][j] = (i == 0) ? 1 : h[i-1][j] + 1;
            }
            else {
                h[i][j] = 0;
            }
        }
    }
    ll res=0;
    for (int i = 0; i < m; i++) {
        stack<ll> st;
        for (int j = 0; j <= n; j++) {
            ll cur= (j == n) ? 0 : h[i][j];
            while(!st.empty() && h[i][st.top()] >= cur) {
                ll height = h[i][st.top()];
                st.pop();
                ll width = (st.empty()) ? j : (j - st.top() - 1);
                res = max(res, height * width);
            }
            st.push(j);
        }
    }
    cout << res << endl;
  return 0;
}
