/**
 *    author:  Dao Le Bao Minh
 *    created: 30.11.2021 08:10:55  
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
const int N = 2e5 + 5;

int n, a[N];
int pf[N], sf[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n;
	pf[0] = -e30; sf[n + 1] = e30;
	For (i, 1, n + 1) cin >> a[i];
	For (i, 1, n + 1) pf[i] = max(pf[i-1], a[i]);
	Rof (i, n + 1, 1) sf[i] = min(sf[i+1], a[i]);

	int ans = 0;
	For (i, 1, n + 1) ans += pf[i] <= sf[i + 1];
	cout << ans;
}