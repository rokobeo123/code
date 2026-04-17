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
ll solve(ll n, const vector<ll> &h, bool ifmax){
    vector<ll> l(n), r(n);
    stack<ll> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && ((ifmax && h[st.top()]<h[i]) || (!ifmax && h[st.top()]>h[i]))){
            st.pop();
        }
        l[i]=(st.empty())?-1:st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && ((ifmax && h[st.top()]<=h[i]) || (!ifmax && h[st.top()]>=h[i]))){
            st.pop();
        }
        r[i]=(st.empty())?n:st.top();
        st.push(i);
    }
    ll res=0;
    for(int i=0;i<n;i++){
        res+=(r[i]-i)*(i-l[i])*h[i];
    }
    return res;
}
int main() {
  fasteio();
  ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n,a,true)-solve(n,a,false) << endl;
  return 0;
}
