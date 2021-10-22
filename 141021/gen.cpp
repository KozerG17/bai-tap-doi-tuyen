/**
 *    author:  dlbm1302
 *    created: 14.10.2021 07:21:24       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("gen.INP", "r", stdin);
	// freopen("gen.OUT", "w", stdout);

	int n; cin >> n;

	const int mod = 1e9 + 7;
	const int N = 1e6 + 5;
	static set<int> a[N];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		int64_t hash = 0, f = true;
		for (int j = 0; s[j]; j++) {
			hash = (27ll*hash + s[j] - 'a' + 1) % mod;
			if (f &= !a[j].insert(hash).second)
				ans = max(ans, j + 2);
		}
	}

	cout << ans;
}