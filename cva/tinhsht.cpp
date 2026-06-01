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
    fre("BAI1");
  fasteio();
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll gcd1 = __gcd(a,b);
    ll gcd2 = __gcd(c,d);
    a /= gcd1;
    b /= gcd1;
    c /= gcd2;
    d /= gcd2;
    ll tongtu=a*d+b*c;
    ll tongmau=b*d;
    ll gcd3 = __gcd(tongtu,tongmau);
    tongtu /= gcd3;
    tongmau /= gcd3;
    if(tongmau<0){
        tongmau=-tongmau;
        tongtu=-tongtu;
    }
    ll hieutu=a*d-b*c;
    ll hieumau=b*d;
    ll gcd4 = __gcd(hieutu,hieumau);
    hieutu /= gcd4;
    hieumau /= gcd4;
    if(hieumau<0){
        hieumau=-hieumau;
        hieutu=-hieutu;
    }
    ll tichtu=a*c;
    ll tichmau=b*d;
    ll gcd5 = __gcd(tichtu,tichmau);
    tichtu /= gcd5;
    tichmau /= gcd5;
        if(tichmau<0){
            tichmau=-tichmau;
            tichtu=-tichtu;
        }
    ll thuongtu=a*d;
    ll thuongmau=b*c;
    ll gcd6 = __gcd(thuongtu,thuongmau);
    thuongtu /= gcd6;
    thuongmau /= gcd6;
        if(thuongmau<0){
            thuongmau=-thuongmau;
            thuongtu=-thuongtu;
        }
    cout << tongtu << " " << tongmau << endl;
    cout << hieutu << " " << hieumau << endl;
    cout << tichtu << " " << tichmau << endl;
    cout << thuongtu << " " << thuongmau << endl;
  //cerr << 1000 * clock() / CLOCKS_PER_SEC;
  return 0;
}
