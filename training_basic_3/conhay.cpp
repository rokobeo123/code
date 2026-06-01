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
  ll n;
  cin >> n;
  vector<ll> a(n+1);
  for(ll i=1;i<=n;i++){
      cin >> a[i];
  }
  vector<vector<ll>> d(n+2, vector<ll>(n+2, INF));
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
  d[2][1] = a[2];
  pq.push({d[2][1], {2, 1}});
  ll res = INF;
  while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ll val = cur.fi;
        ll i = cur.se.fi;
        ll j = cur.se.se;
        if(i == n){
            res = min(res, val);
            break;
        }
        if(val > d[i][j]) continue;
        ll nexti = i+j+1;
        ll nextj = j+1;
        if(nexti <= n && nextj <= n){
            if(d[nexti][nextj] > val + a[nexti]){
                d[nexti][nextj] = val + a[nexti];
                pq.push({d[nexti][nextj], {nexti, nextj}});
            }
        }
        ll backi = i-j;
        if(backi > 0){
            if(d[backi][j] > val + a[backi]){
                d[backi][j] = val + a[backi];
                pq.push({d[backi][j], {backi, j}});
            }
        }
    }
    cout << res;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
