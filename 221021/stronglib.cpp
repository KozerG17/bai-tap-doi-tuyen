/**
 *    author:  dlbm1302
 *    created: 21.10.2021 07:41:48       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

const int N = 1e5*1.1;

int n, m, a[N];
bool check(int val) {
	int c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) {
		c0 += a[i] >= val;
		c1 += a[i] == val - 1;
	}
	return c0 + min(c1, m) >= val;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("stronglib.INP", "r", stdin);
	freopen("stronglib.OUT", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int low = 0, high = n;
	while (low <= high) {
		int mid = (low + high)/2;
		if (check(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << high;
}