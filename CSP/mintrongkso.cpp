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
  ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<ll> dq;
    for(int i = 0; i < n; i++) {
        while(!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(dq.front() + k <= i) {
            dq.pop_front();
        }
        if(i >= k - 1) {
            cout << a[dq.front()] << endl;
            if(dq.front() == i - k + 1) {
                dq.pop_front();
            }
        }
    }
  return 0;
}
