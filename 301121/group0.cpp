/**
 *    author:  Dao Le Bao Minh
 *    created: 30.11.2021 08:34:00  
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
const int N = 55, K = 25;

ll n, k, a[N];
ll calc(ll m) {
	ll cnt = 0, rem = m;
	For (i, 0, n) {
		if (a[i] < rem) rem -= a[i];
		else cnt++, rem = m - (min(a[i], m) - rem);
	}
	return cnt;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n >> k;
	For (i, 0, n) cin >> a[i];

	ll lo = 1, hi = 1e11;
	while (lo <= hi) {
		ll mid = (lo + hi)/2;
		if (calc(mid) >= k)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	cout << hi;
}