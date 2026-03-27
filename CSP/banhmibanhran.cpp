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

int main()
{
    fasteio();
    ll n, k;
    cin >> n >> k;
    vector<int> s(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        s[i] = (c == '1');
    }

    vector<ll> l(n + 2, 0), r(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 1)
            l[i] = l[i - 1] + 1;
        else
            l[i] = 0;
    }

    for (int i = n; i >= 1; i--)
    {
        if (s[i] == 1)
            r[i] = r[i + 1] + 1;
        else
            r[i] = 0;
    }

    ll ans = 0;
    for (int i = 1; i <= n - k + 1; i++)
    {
        ans = max(ans, l[i - 1] + k + r[i + k]);
    }

    cout << ans;
    return 0;
}
