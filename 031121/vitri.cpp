/**
 *    author:  Dao Le Bao Minh
 *    created: 03.11.2021 08:02:36  
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
const int N = 205, K = 35;

int n, k, dp[N][K];
int a[N], split[N][N];
int trace[N][K];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n >> k;
	fill(*dp, *dp + N*K, e30);
	fill(*split, *split + N*N, e30);
	For (i, 1, n + 1) cin >> a[i];
	For (l, 1, n + 1) For (r, 1, n + 1) {
		split[l][r] = 0;
		For (i, l + 1, r - 1) {
			int val = min(a[i] - a[l], a[r] - a[l]);
			split[l][r] = max(split[l][r], val);
		}
	}
	For (i, 1, n + 1) split[0][i] = 0;

	dp[0][0] = 0;
	For (i, 1, n + 1) For (c, 1, k + 1) {
		For (j, 0, i) {
			int val = max(split[j][i], dp[j][c - 1]);
			if (val < dp[i][c]) {
				trace[i][c] = j;
				dp[i][c] = val;
			}
		}
	}

	int minDiff = e30, last;
	Rof (i, n + 1, 1) {
		int res = max(a[n] - a[i], dp[i][k]);
		if (res < minDiff) minDiff = res, last = i;
	}

	while (last != 0) {
		cout << last << '\n';
		last = trace[last][k--];
	}
}