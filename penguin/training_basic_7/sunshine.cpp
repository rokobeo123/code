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
struct pig{
    ll minspf,maxspf;
};
struct sunshine{
    ll spf,cnt;
};
bool cmp(sunshine a,sunshine b){
    return a.spf<b.spf;
}
bool cmp2(pig a,pig b){
    return a.minspf<b.minspf;
}
int main() {
  fasteio();
    ll c,l;
    cin >> c >> l;
    vector<pig> a(c);
    for(ll i = 0; i < c; i++){
        cin >> a[i].minspf >> a[i].maxspf;
    }
    sort(all(a),cmp2);
    vector<sunshine> b(l);
    for(ll i = 0; i < l; i++){
        cin >> b[i].spf >> b[i].cnt;
    }
    sort(all(b),cmp);
    ll j = 0;
    ll ans = 0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i = 0; i < l; i++){
        while(j<c && a[j].minspf<=b[i].spf){
            pq.push(a[j].maxspf);
            j++;
        }
        while(!pq.empty() && pq.top()<b[i].spf) pq.pop();
        ll cnt = b[i].cnt;
        while(cnt>0 && !pq.empty()){
            ans++;
            pq.pop();
            cnt--;
        }
    }
    cout << ans;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
