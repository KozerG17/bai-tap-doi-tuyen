/**
 *    author:  dlbm1302
 *    created: 15.10.2021 07:42:48       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

const int N = 1e6 + 5;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("matong.INP", "r", stdin);
	freopen("matong.OUT", "w", stdout);

	vector<int> prime, lpf(N);
	vector<int> mult(N), cnt(N);

	mult[1] = cnt[1] = 1;
	for (int i = 2; i < N; i++) {
		if (lpf[i] == 0) {
			lpf[i] = mult[i] = i;
			cnt[i] = 2;
			prime.push_back(i);
		}
		for (int j : prime)
			if (j <= lpf[i] && i*j < N) {
				lpf[i*j] = j;
				if (j != lpf[i]) {
					mult[i*j] = j;
					cnt[i*j] = 2*cnt[i];
				} else {
					mult[i*j] = mult[i]*j;
					int splitA = cnt[i / mult[i]];
					int splitB = cnt[mult[i]] + 1;
					cnt[i*j] = splitA * splitB;
				}
			} else break;
	}

	int n; cin >> n;
	long long ans = 0;

	while (n--) {
		long long x; cin >> x;
		ans += x * cnt[x];
	}

	cout << ans;
}