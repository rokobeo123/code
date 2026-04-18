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
    string val;
    ll id;
    ll idx;
};
ll dem(string s){
    ll ret=0;
    for(int i=0;i<s.size();i++){
        if(s[i] >= '0' && s[i] <= '9') ret++;}
    return ret;
}
bool cmp(Node a, Node b){
    if(a.id == b.id) return a.idx < b.idx;
    return a.id < b.id;
}
int main() {
    fre("trochoi");
  fasteio();
  ll n;
    cin >> n;
    vector<Node> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].val;
        ll cnt = dem(a[i].val);
        a[i].id = cnt;
        a[i].idx = i;
    }
    sort(all(a), cmp);
    for(auto x : a) cout << x.val << endl;
  return 0;
}
