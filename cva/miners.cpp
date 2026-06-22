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
ll point(ll a, ll b, ll nxt){
    ll res=1;
    if(a != 0 && a != nxt) res++;
    if(b != 0 && b != nxt && b != a) res++;
    return res;
}
int main() {
  fasteio();
    ll n;
    string s;
    cin >> n >> s;
    ll dp[4][4][4][4];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;
    for(int i=0; i<n; i++){
        ll nxt;
        if(s[i]== 'M') nxt = 1;
        else if(s[i] == 'F') nxt = 2;
        else nxt = 3;
        ll temp[4][4][4][4];
        memset(temp, -1, sizeof(temp));
        for(int c1=0; c1<4; c1++){
            for(int c2=0; c2<4; c2++){
                for(int c3=0; c3<4; c3++){
                    for(int c4=0; c4<4; c4++){
                        if(dp[c1][c2][c3][c4] == -1) continue;
                        ll p1=point(c1, c2, nxt);
                        ll nxtc1=c2;
                        ll nxtc2=nxt;
                        temp[nxtc1][nxtc2][c3][c4] = max(temp[nxtc1][nxtc2][c3][c4], dp[c1][c2][c3][c4] + p1);
                        ll p2=point(c3, c4, nxt);
                        ll nxtc3=c4;
                        ll nxtc4=nxt;
                        temp[c1][c2][nxtc3][nxtc4] = max(temp[c1][c2][nxtc3][nxtc4], dp[c1][c2][c3][c4] + p2);
                    }
                }
            }
        }
        memcpy(dp, temp, sizeof(dp));
    }
    ll ans = 0;
    for(int c1=0; c1<4; c1++){
        for(int c2=0; c2<4; c2++){
            for(int c3=0; c3<4; c3++){
                for(int c4=0; c4<4; c4++){
                    ans = max(ans, dp[c1][c2][c3][c4]);
                }
            }
        }
    }
    cout << ans << endl;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
