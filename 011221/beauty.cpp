/**
 *    author:  Dao Le Bao Minh
 *    created: 01.12.2021 07:11:53  
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
const int N = 3e5 + 5;

ll n, a[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("beauty.INP", "r", stdin);
	// freopen("beauty.OUT", "w", stdout);
	
	cin >> n;
	For (i, 1, n + 1) cin >> a[i];
	partial_sum(a, a + n + 1, a);

	ll ans = -e60, mx = -e60;
	for (int i = n-4; i >= 0; i -= 2) {
		mx = max(mx, a[i + 4]);
		ans = max(ans, mx - a[i]);
	}

	mx = -e60;
	for (int i = n-5; i >= 0; i -= 2) {
		mx = max(mx, a[i + 4]);
		ans = max(ans, mx - a[i]);
	}

	cout << ans << '\n';
}