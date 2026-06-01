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
struct loinhuan{
    ll x,y,z;
};
bool cmp(loinhuan a, loinhuan b){
    return (a.x - a.y) > (b.x - b.y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll X,Y,Z;
    cin >> X >> Y >> Z;
    ll N = X + Y + Z;
    vector<loinhuan> a(N);
    ll tong = 0;
    for(ll i=0;i<N;i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
        tong += a[i].z;
        a[i].x -= a[i].z;
        a[i].y -= a[i].z;
    }
    sort(all(a), cmp);
    vector<ll> pre(N,-INF), suf(N,-INF);
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum = 0;
        for(ll i=0;i<N;i++){
            pq.push(a[i].x);
            sum += a[i].x;
            if(pq.size() > X){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == X){
                pre[i] = sum;
            }
        }
        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        ll sum2 = 0;
        for(ll i=N-1;i>=0;i--){
            pq2.push(a[i].y);
            sum2 += a[i].y;
            if(pq2.size() > Y){
                sum2 -= pq2.top();
                pq2.pop();
            }
            if(pq2.size() == Y){
                suf[i] = sum2;
            }
        }
    ll ans = 0;
    for(ll i=X-1;i<=N-Y-1;i++){
        ans = max(ans, pre[i] + suf[i+1]);
    }
    cout << tong + ans;
}
