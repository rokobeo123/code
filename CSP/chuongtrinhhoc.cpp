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
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> adj(n+1);
    vector<ll> ok(n+1, 0);
    for(int i = 0; i < m; i++){
        ll u,v;
        cin >> u >> v;
        adj[u].pb(v);
        ok[v]++;
    }
    queue<ll> q;
    for(int i = 1; i <= n; i++){
        if(ok[i] == 0) q.push(i);
    }
    vector<ll> res;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        res.pb(u);
        for(auto v : adj[u]){
            ok[v]--;
            if(ok[v] == 0) q.push(v);
        }
    }
    if(res.size() != n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(auto x : res){
        cout << x << " ";
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
