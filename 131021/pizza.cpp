/**
 *    author:  dlbm1302
 *    created: 13.10.2021 07:09:05       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("pizza.INP", "r", stdin);
	freopen("pizza.OUT", "w", stdout);

	int n; cin >> n;

	const int N = 105;
	vector<int> mark(N);
	while (n--) {
		int x; cin >> x;
		mark[x] = true;
	}

	int ans = 0;
	for (cin >> n; n--; ) {
		bool ok = true;
		int k; cin >> k;
		while (k--) {
			int x; cin >> x;
			ok &= !mark[x];
		}
		ans += ok;
	}

	cout << ans;
}