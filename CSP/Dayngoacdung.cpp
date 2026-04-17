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
  ll n;
  cin >> n;
  while(n--){
    string s;
    cin >> s;
    stack<char> st;
    bool is_balanced = true;
    for(char c : s){
        if(c == '(' || c == '{' || c == '[') st.push(c);
        else{
            if(st.empty()){
                cout << "NO" << endl;
                is_balanced = false;
                break;
            }
            char top = st.top();
            st.pop();
            if((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')){
                cout << "NO" << endl;
                is_balanced = false;
                break;
            }
        }
    }
    if(st.empty() && is_balanced) cout << "YES" << endl;
    else if(is_balanced) cout << "NO" << endl;
  }
}
