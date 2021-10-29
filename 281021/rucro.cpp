/**
 *    author:  Dao Le Bao Minh
 *    created: 28.10.2021 07:40:23  
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

int n; str s;
int nxt[N][27];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("rucro.INP", "r", stdin);
	// freopen("rucro.OUT", "w", stdout);
	
	cin >> n >> s;
	fill(nxt[n], nxt[n] + 27, n);
	Rof (i, n, 0) {
		For (k, 0, 27)
			nxt[i][k] = nxt[i + 1][k];
		nxt[i][s[i] - 'a'] = i;
	}

	ll p = 1, q = 1, l = 0, r = 0;
	For (i, 0, n) {
		sort(nxt[i], nxt[i] + 26);
		For (j, 1, 27) {
			if (nxt[i][j - 1] == n) break;
			int rg = nxt[i][j] - 1;
			if (p*(rg - i + 1) > q*j) {
				l = i; r = rg;
				p = j; q = rg - i + 1;
			}
		}
	}
	cout << l + 1 << ' ' << r + 1;
}