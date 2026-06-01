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
  ll t,n;
  cin >> t >> n;
    vector<ll> a(n+1);
    ll sum = 0;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> nhom(t+1, -1);
    vector<ll> d(t+1, -1);
    nhom[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=t;j>=a[i];j--){
            if(nhom[j]== -1 && nhom[j-a[i]] != -1){
                nhom[j] = i;
                d[j] = j - a[i];
            }
        }
    }
    ll tar=-1;
    ll low=max(0LL, sum - t);
    for(int i=t;i>=low;i--){
        if(nhom[i] != -1 && sum - i <= t){
            tar = i;
            break;
        }
    }
    vector<ll> res(n+1, 1);
    ll cur = tar;
    while(cur > 0){
        res[nhom[cur]] = 2;
        cur = d[cur];
    }
    vector<ll> ans(n+1);
    ll idx1 = 0, idx2 = 0;
    for(int i=1;i<=n;i++){
        if(res[i] == 2){
            ans[i] = idx1;
            idx1+=a[i];
        }
        else{
            ans[i] = idx2;
            idx2+=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
