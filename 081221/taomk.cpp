/**
 *    author:  Dao Le Bao Minh
 *    created: 08.12.2021 08:34:40  
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
const int N = 1005;

int n, m, k;
str s, t;
int dp[N][N][11];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n >> m >> k;
	cin >> s; s = '0' + s;
	cin >> t; t = '1' + t;

	For (h, 1, k + 1)
	For (i, 1, n + 1) For (j, 1, m + 1) {
		if (int &res = dp[i][j][h]; s[i] != t[j])
			res = max(dp[i-1][j][h], dp[i][j-1][h]);
		else if (s[i-1] == t[j-1])
			res = dp[i-1][j-1][h] + 1;
		else
			res = dp[i-1][j-1][h-1] + 1;
	}
	cout << *max_element(**dp, **dp + 11*N*N) << '\n';
}