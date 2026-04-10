#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define umap unordered_map
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
ll sum(ll l, ll r){
    return (l+r)*(r-l+1)/2;
}
int main() {
    //fre("bai1");
  fasteio();
  ll l,r;
  cin >> l >> r;
  ll s=sum(l,r);
  ll ans=0;
  ll diff=INF;
  ll le=l,ri=r-1;
   while(le<=ri){
    ll mid=(le+ri)/2;
    ll s1=sum(l,mid);
    ll s2=sum(mid+1,r);
    if(abs(s1-s2)<diff){
        diff=abs(s1-s2);
        ans=mid;
    }
    if(s1<s2){
        le=mid+1;
    }
    else{
        ri=mid-1;
    }
   }
    cout << ans;
  return 0;
}
