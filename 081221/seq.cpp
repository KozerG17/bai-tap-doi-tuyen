/**
 *    author:  Dao Le Bao Minh
 *    created: 08.12.2021 07:22:30  
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

const ll mod = 1e9 + 7,        luv = 17 * 83;
const ll e30 = 1ll << 30,      e60 = 1ll << 60;



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const int N = 1e6 + 5;

int n, a[N], p[N], prv[N], nxt[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n; a[0] = a[n+1] = e30;
	For (i, 1, n + 1) {
		cin >> a[i]; p[i] = i;
		prv[i] = i-1; nxt[i] = i+1;
	}

	sort(p + 1, p + n + 1,
		[](int u, int v) {
		return a[u] < a[v];
	});

	ll ans = 0;
	For (j, 1, n) {
		int i = p[j];
		ans += min(a[prv[i]], a[nxt[i]]);
		nxt[i-1] = nxt[i]; prv[i+1] = prv[i];
	}
	cout << ans << '\n';
}