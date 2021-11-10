/**
 *    author:  Dao Le Bao Minh
 *    created: 08.11.2021 08:50:35  
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

const ll mod = 1e9,            luv = 18 * 13;
const ll e30 = 1ll << 30,      e60 = 1ll << 60;



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const int N = 205, L = 20005;

int n, l, a[N][L];
int calc(int u, int lim) {
	return upper_bound(a[u], a[u] + l, lim) - a[u];
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("TV.INP", "r", stdin);
	// freopen("TV.OUT", "w", stdout);
	
	cin >> n >> l;
	For (i, 0, n) For (j, 0, l) cin >> a[i][j];

	int ans = 0;
	For (i, 0, n) For (j, 0, n) {
		if (i == j) continue;
		int low = 0, high = l - 1, res = 0;
		while (low <= high) {
			int mid = (low + high)/2;
			int Min = calc(j, a[i][mid] - 1);
			int Max = calc(j, a[i][mid]);
			debug(a[i][mid], Min, Max);
			if (mid + Min > l) high = mid - 1;
			else if (mid + Max < l) low = mid + 1;
			else { res = a[i][mid]; break; }
		}
		ans = (ans + res) % mod; debug(res);
	}
	cout << ans << '\n';
}