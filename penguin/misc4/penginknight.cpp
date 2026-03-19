#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
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
const ll NEG=-1e15;
int main(){
    fasteio();
    ll n;
    cin >> n;
    vector<ll> dp(10, NEG);
    dp[0] = 0;

    for (ll r = 1; r <= n; r++){
        ll k;
        cin >> k;
        vector<ll> c1, c2, c3;
        for (ll i = 0; i < k; i++){
            ll c, d;
            cin >> c >> d;
            if (c == 1)
                c1.pb(d);
            else if (c == 2)
                c2.pb(d);
            else
                c3.pb(d);
        }
        sort(allr(c1));
        sort(allr(c2));
        sort(allr(c3));
        vector<ll> b(4, NEG), a(4, NEG);
        b[0] = 0;
        a[0] = 0;
        ll t1 = NEG, t2 = NEG, t3 = NEG;
        if (!c1.empty()) t1 = max(t1, c1[0]);
        if (!c2.empty()) t2 = max(t2, c2[0]);
        if (!c3.empty()) t3 = max(t3, c3[0]);
        if (t1 != NEG){
            b[1] = t1;
            a[1] = 2 * t1;
        }
        if (c1.size() >= 2){
            ll sum = c1[0] + c1[1];
            b[2] = max(b[2], sum);
            a[2] = max(a[2], 2 * c1[0] + c1[1]);
        }
        if (!c1.empty() && !c2.empty()){
            ll x = c1[0], y = c2[0];
            b[2] = max(b[2], x + y);
            a[2] = max(a[2], x + y + max(x, y));
        }
        if (c1.size() >= 3){
            ll sum = c1[0] + c1[1] + c1[2];
            b[3] = sum;
            a[3] = 2 * c1[0] + c1[1] + c1[2];
        }
        vector<ll> ndp(10, NEG);
        for (ll r = 0; r < 10; r++){
            if (dp[r] == NEG) continue;
            for (ll t = 0; t <= 3; t++){
                if (b[t] == NEG)
                    continue;
                ll nr = (r + t) % 10;
                ll add = (r + t >= 10 ? a[t] : b[t]);
                ndp[nr] = max(ndp[nr], dp[r] + add);
            }
        }
        dp.swap(ndp);
    }
    cout << *max_element(all(dp)) << "\n";
    return 0;
}
