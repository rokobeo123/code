#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
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
  ll n,m;
  cin >> n >> m;
  vector<ll> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<ll> q;
  q.push(1);
  while(!q.empty()){
    ll u= q.front();
    q.pop();
    for(auto v: adj[u]){
      
    }
  }
  return 0;
}
