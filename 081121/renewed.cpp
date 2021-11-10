/**
 *    author:  Dao Le Bao Minh
 *    created: 08.11.2021 08:26:35  
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
ll a, k, b, m, n;
bool isOverflow(ll a, ll b) {
	return a > e60/b;
}
ll calc(ll days) {
	if (isOverflow(days - days/k, a)) return e60;
	if (isOverflow(days - days/m, b)) return e60;
	return (days - days/k)*a + (days - days/m)*b;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("renewed.INP", "r", stdin);
	freopen("renewed.OUT", "w", stdout);
	
	cin >> a >> k >> b >> m >> n;
	ll low = 1, high = e60;
	while (low <= high) {
		ll mid = (low + high)/2;
		if (calc(mid) < n)
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << low << '\n';
}