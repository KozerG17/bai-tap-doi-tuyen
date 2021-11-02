/**
 *    author:  Dao Le Bao Minh
 *    created: 01.11.2021 08:32:03  
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
const int N = 505;

int n, a[N][N];
int b[N][N], c[N][N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("bonus100.INP", "r", stdin);
	freopen("bonus100.OUT", "w", stdout);
	
	fill(*b, *b + N*N, N);
	fill(*c, *c + N*N, N);

	cin >> n;
	For (i, 0, n) For (j, 0, n) {
		int x; cin >> x;
		if (x == 100) {
			Rof (pos, j + 1, 0) {
				if (b[i][pos] == N)
					b[i][pos] = j;
				else break;
			}
		} else if (x < 100) {
			Rof (pos, j + 1, 0) {
				if (c[i][pos] == N)
					c[i][pos] = j;
				else break;
			}
		}
	}

	long long ans = 0;
	For (l, 0, n) For (r, l, n) {
		int i = 0, m = -1, j = -1;
		while (j + 1 < n) { j++;
			if (c[j][l] <= r) {
				i = j + 1; m = -1;
				continue;
			}
			if (b[j][l] <= r) m = j;
			if (m != -1) ans += m - i + 1;
		}
	}
	cout << ans;
}