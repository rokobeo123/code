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
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

vector<ll> rtong(const vector<ll> &v)
{
    vector<ll> sums;
    sums.pb(0);
    for (ll x : v)
    {
        int cur = (int)sums.size();
        for (int i = 0; i < cur; i++)
        {
            sums.pb(sums[i] + x);
        }
    }
    return sums;
}

int main()
{
    fasteio();
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll tong = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        tong += a[i];
    }

    int mid = n / 2;
    vector<ll> lp(a.begin(), a.begin() + mid);
    vector<ll> rp(a.begin() + mid, a.end());

    vector<ll> ls = rtong(lp);
    vector<ll> rs = rtong(rp);
    sort(all(rs));

    ll ans = LLONG_MAX;
    ll it = tong / 2;

    for (ll x : ls)
    {
        ll need = it - x;
        auto it = lower_bound(all(rs), need);

        if (it != rs.end())
        {
            ll s = x + *it;
            ans = min(ans, llabs(tong - 2 * s));
        }
        if (it != rs.begin())
        {
            --it;
            ll s = x + *it;
            ans = min(ans, llabs(tong - 2 * s));
        }
    }

    cout << ans << "\n";
    return 0;
}

