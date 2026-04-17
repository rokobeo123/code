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
ll solve(ll n, const vector<ll> &h){
    stack<ll> st;
    st.push(0);
    ll res=0;
    for(int i=1;i<n;i++){
        while(!st.empty() && h[st.top()]>=h[i]){
            ll height=h[st.top()];
            st.pop();
            ll width=(st.empty())?i:(i-st.top()-1);
            res=max(res,height*width);
        }
        st.push(i);
    }
    return res;
}
int main() {
  fasteio();
  ll m,n;
  cin >> m >> n;
  vector<ll> h(n);
  vector<ll> w(n);
  for(int i=0;i<n;i++){
    cin >> h[i];
    w[i]=m-h[i];
  }
  stack<ll> st;
  cout << max(solve(n,h),solve(n,w)) << endl;
  return 0;
}
