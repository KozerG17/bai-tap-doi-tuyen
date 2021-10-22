/**
 *    author:  1411
 *    created: 18.10.2021 07:58:45       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("bai2.INP", "r", stdin);
	freopen("bai2.OUT", "w", stdout);

	int n, m, k, x; string s;
	cin >> n >> m >> k >> x >> s;

	vector<string> a(m); x--;
	for (string &x : a) {
		cin >> x;
		sort(x.begin(), x.end());
	}
	
	for (int i = n - 1, j = m - 1; j >= 0; i--, j--) {
		while (s[i] != '#') i--;
		s[i] = a[j][x % k]; x /= k;
	}

	cout << s;
}