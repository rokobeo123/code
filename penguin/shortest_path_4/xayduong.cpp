#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unordered_map
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ford(i, a, b) for (int i = int(a); i >= int(b); i--)
#define allr(x) x.rbegin(), x.rend()
#define fasteio()                \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
void fre(const char *tenbai)
{
    string input_file = string(tenbai) + ".INP";
    string output_file = string(tenbai) + ".OUT";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}
const ll INF = 4e18;
const ll MOD = 1e9 + 7;

int main(){
    fasteio();
    ll n;
    cin >> n;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1));
    for1(i, n){
        for1(j, n){
            cin >> dist[i][j];
        }
    }
    int k;
    cin >> k;
    for (int q = 0; q < k; q++){
        ll a, b, c;
        cin >> a >> b >> c;
        for1(i, n){
            for1(j, n){
                ll d1 = dist[i][a] + c + dist[b][j];
                ll d2 = dist[i][b] + c + dist[a][j];
                dist[i][j] = min(dist[i][j], min(d1, d2));
            }
        }
        ll ans = 0;
        for1(i, n){
            for (int j = i + 1; j <= n; j++){
                ans += dist[i][j];
            }
        }
        cout << ans;
    }
    return 0;
}
