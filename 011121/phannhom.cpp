/**
 *    author:  Dao Le Bao Minh
 *    created: 01.11.2021 07:39:54  
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
const int N = 1e4 + 5;

int n, k, a[N], dp[N + 1];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("phannhom.INP", "r", stdin);
	freopen("phannhom.OUT", "w", stdout);
	
	cin >> n >> k;
	For (i, 1, n + 1) {
		cin >> a[i]; int mx = a[i];
		Rof (j, i, max(0, i - k)) {
			int sum = mx*(i-j);
			dp[i] = max(dp[i], dp[j]+sum);
			mx = max(mx, a[j]);
		}
	}
	cout << dp[n];
}