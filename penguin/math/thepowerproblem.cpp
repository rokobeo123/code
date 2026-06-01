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
    ll a,b;
    cin >> a >> b;
    vector<bool> pw(a+1,false);
    for(int i=2;i*i <= a;i++){
        ll cur= i*i;
        while(cur <= a){
            pw[cur] = true;
            if(cur > a/i) break;
            cur *= i;
        }
    }
    vector<ll> f(25,0);
    vector<bool> used(25*b+1,false);
    ll ans = 0;
    for(int i=1;i<=20;i++){
        for(int j=1;j<=b;j++){
            if(!used[i*j]){
                used[i*j] = true;
                ans++;
            }
        }
        f[i] = ans;
    }
    ll res =1;
    for(ll i=2;i<=a;i++){
        if(pw[i]) continue;
        ll cur = i;
        ll t= 0;
        while(cur <= a){
            t++;
            if(cur > a/i) break;
            cur *= i;
        }
        res+= f[t];
    }
    cout << res << endl;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
