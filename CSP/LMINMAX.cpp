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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<ll> dq_max;
    deque<ll> dq_min;
    ll l=0, ans=0;
    for(int i = 0; i < n; i++){
        while(!dq_max.empty() && a[dq_max.back()] <= a[i]) {
            dq_max.pop_back();
        }
        dq_max.push_back(i);
        while(!dq_min.empty() && a[dq_min.back()] >= a[i]) {
            dq_min.pop_back();
        }
        dq_min.push_back(i);
        while(!dq_min.empty()&& !dq_max.empty() && a[dq_max.front()] - a[dq_min.front()] > k) {
            l++;
            if(dq_max.front() < l) {
                dq_max.pop_front();
            }
            if(dq_min.front() < l) {
                dq_min.pop_front();
            }
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
  return 0;
}
