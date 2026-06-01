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
bool solve(ll n, ll p, ll q, ll hang, vector<ll> &a, vector<bool> &uutien, ll tong){
    vector<bool> dp(q+1, false);
    vector<vector<bool>> trace(n, vector<bool>(q+1, false));
    dp[0] = true;
    for(ll i=0;i<n;i++){
        if(i==0) continue;
        for(ll j=q;j>=a[i];j--){
            if(dp[j-a[i]]){
                dp[j] = true;
                trace[i][j] = true;
            }
        }
    }
    ll conlai = -1;
    if(hang == 1) conlai = q;
    else conlai = q - a[0];
    for(ll j=conlai;j>=0;j--){
        if(dp[j]){
            ll hangduoi=j;
            if(hang == 2) hangduoi += a[0];
            ll hangtren = tong - hangduoi;
            if(hangtren <=p && hangduoi <= q){
                ll cur = j;
                for(ll i=n-1;i>=0;i--){
                    if(i==0){
                        uutien[0] = (hang == 1);
                    }
                    else if(trace[i][cur]){
                        uutien[i] = false;
                        cur -= a[i];
                    }
                }
                return true;
            }
        }
    }
    return false;
}
void in(ll n, ll hang, vector<ll> &a, vector<bool> &uutien){
    vector<ll> tren, duoi;
    for(ll i=0;i<n;i++){
        if(uutien[i]){
            tren.pb(i+1);
        }
        else{
            duoi.pb(i+1);
        }
    }
    cout << hang << endl;
    cout << tren.size() << " ";
    for(ll i=0;i<tren.size();i++){
        cout << tren[i] << " ";
    }
    cout << endl;
    cout << duoi.size() << " ";
    for(ll i=0;i<duoi.size();i++){
        cout << duoi[i] << " ";
    }
}
int main() {
  fasteio();
  ll n,p,q;
  cin >> n >> p >> q;
    vector<ll> a(n);
  ll tong = 0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        tong += a[i];
    }
    vector<bool> uutien(n, true);
    if(solve(n,p,q,1,a,uutien, tong)){
        in(n, 1, a, uutien);
    }
    else if(solve(n,p,q,2,a,uutien, tong)){
        in(n, 2, a, uutien);
    }
    else{
        cout << -1;
    }

  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
