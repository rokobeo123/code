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

int main() {
	fasteio();

	string s;
	cin >> s;

	int n = (int)s.size();
	vector<int> pi(n, 0);

	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		pi[i] = j;
	}

	int p = n - pi[n - 1];
	if (n % p == 0) {
		cout << s.substr(0, p);
	} else {
		cout << s;
	}

	return 0;
}
