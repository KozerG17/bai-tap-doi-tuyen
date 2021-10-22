/**
 *    author:  dlbm1302
 *    created: 13.10.2021 08:00:43       
**/

#include <bits/stdc++.h>
using namespace std;

int a, b, ans = 0;

bool check(long long x) {
	if (x < max(a, 2) || x > b)
		return false;
	for (int i = 2; i*i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("auction.INP", "r", stdin);
	freopen("auction.OUT", "w", stdout);

	cin >> a >> b;

	for (int mask = 0; mask <= 99999; mask++) {
		string s = to_string(mask);
		string t = s;
		reverse(t.begin(), t.end());
		ans += check(atoll((s + t).c_str()));
		s.pop_back();
		ans += check(atoll((s + t).c_str()));
	}

	cout << ans;
}