/**
 *    author:  Dao Le Bao Minh
 *    created: 08.11.2021 08:12:32  
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

int n, a[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("ghepcap.INP", "r", stdin);
	freopen("ghepcap.OUT", "w", stdout);
	
	cin >> n;
	For (i, 0, n) cin >> a[i];
	sort(a, a + n);

	ll ans = 0, l = 0;
	For (r, 0, n) {
		ll lim = (9ll*a[r] + 9)/10;
		while (a[l] < lim) l++;
		ans += r - l;
	}
	cout << ans << '\n';
}