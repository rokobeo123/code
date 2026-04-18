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
struct Node{
    ll val;
    ll id;
};
bool cmp(Node a, Node b){
    if(a.val == b.val) return a.id < b.id;
    return a.val < b.val;
}
bool cmp2(Node a, Node b){
    return a.id < b.id;
}
int main() {
    fre("SDB");
  fasteio();
  ll n;
  cin >> n;
  vector<Node> a(n);
  ll total = 0;
    for(int i=0;i<n;i++){
        cin >> a[i].val;
        a[i].id = i;
    }
    vector<Node> ans;
    sort(all(a), cmp);
    for(int i=0;i<n;i++){
        bool ok = true;
        if(i > 0 && a[i].val == a[i-1].val) ok = false;
        if(i < n-1 && a[i].val == a[i+1].val) ok = false;
        if(ok) ans.pb(a[i]);
    }
    sort(all(ans), cmp2);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x.val << endl;
  return 0;
}
