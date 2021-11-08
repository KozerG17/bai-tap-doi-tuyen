/**
 *    author:  Dao Le Bao Minh
 *    created: 02.11.2021 08:00:21  
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

// /* 
#define fi first
#define se second
// */

#define all(a)  (a).begin(),  (a).end()
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rof(i, a, b) for (int i = a; --i >= b; )

using namespace std;           using ll  = long long;
using str = string;            using ld  = long double;
using pii = pair<int, int>;    using pll = pair<ll, ll>;

const ll mod = 1e9 + 7,        luv = 18 * 13;
const ll e30 = 1ll << 30,      e60 = 1ll << 60;



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const int N = 1e5 + 5;

int n, m, a[N], b[N];
ll calc(int val) {
	int Min = val;
	Rof (i, n, 0)
		b[i] = Min = max(Min, a[i]);
	ll ans = 0; Min = val;
	For (i, 0, n) {
		Min = max(Min, a[i]);
		ans += min(b[i], Min) - max(a[i], val);
	}
	return ans;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n >> m;
	For (i, 0, n) cin >> a[i];
	if (calc(0) < m)
		return cout << -1, 0;

	int low = 0, high = 2e9;
	while (low <= high) {
		int mid = (low + high)/2;
		if (calc(mid) < m)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << high;
}