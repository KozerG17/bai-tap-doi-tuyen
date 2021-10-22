/**
 *    author:  dlbm1302
 *    created: 14.10.2021 07:21:39       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("qstring.INP", "r", stdin);
	freopen("qstring.OUT", "w", stdout);

	string s; cin >> s;
	int n = s.size();
	s = ' ' + s;

	const int N = 1e5 + 5;
	static int p[26][N];
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 26; k++)
			p[k][i] = p[k][i - 1];
		p[s[i] - 'a'][i]++;
	}

	int q; cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		bool ok = true;
		for (int k = 0; k < 26; k++) {
			int n0 = p[k][b] - p[k][a - 1];
			int n1 = p[k][d] - p[k][c - 1];
			ok &= n0 == n1;
		}
		cout << "NO\0YES" + 3*ok << '\n';
	}
}