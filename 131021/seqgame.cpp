/**
 *    author:  dlbm1302
 *    created: 13.10.2021 07:13:05       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("seqgame.INP", "r", stdin);
	freopen("seqgame.OUT", "w", stdout);

	int n, m; cin >> n >> m;

	const int N = 1e5 + 5;
	vector<int64_t> a(n + 2);
	static vector<pair<int, int64_t>> q[N];
	for (int i = 0; i < m; i++) {
		int l, r, d; cin >> l >> r >> d;
		q[l].emplace_back(r, d);
		a[l] += d; a[r + 1] -= d;
	}

	static int64_t rmq[N][20];
	for (int i = 1; i <= n; i++)
		rmq[i][0] = rmq[i - 1][0] + a[i];
	for (int k = 1; k < 20; k++)
		for (int i = 1; i <= n - (1 << (k - 1)); i++) {
			int j = i + (1 << (k - 1));
			rmq[i][k] = max(rmq[i][k - 1], rmq[j][k - 1]);
		}
	auto getMax = [&n](int l, int r) -> int64_t {
		if (r < l) return 0ll;
		int k = 31 - __builtin_clz(r - l + 1);
		return max(rmq[l][k], rmq[r - (1 << k) + 1][k]);
	};

	int64_t ans = 1ll << 60;
	for (int l = 1; l <= n; l++)
		for (auto &[r, d] : q[l]) {
			int64_t a = getMax(1, l - 1);
			int64_t b = getMax(r + 1, n);
			int64_t c = getMax(l, r) - d;
			ans = min(ans, max({a, b, c}));
		}
	cout << ans;
}