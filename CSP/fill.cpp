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
void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll res=0;
    stack<ll> st;
    st.push(0);
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() > a[i]) {
            st.pop();
        }
        if(st.top() < a[i]) {
            res+= 1;
            st.push(a[i]);
        }
    }
    cout << res << endl;
}
int main() {
  fasteio();
  ll t;
    cin >> t;
    while(t--){
        solve();
    }
  return 0;
}
