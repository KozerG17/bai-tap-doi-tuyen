/**
 *    author:  Dao Le Bao Minh
 *    created: 26.10.2021 07:36:23  
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

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

int n, q, a[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n >> q;
	For (i, 0, n) cin >> a[i];

	while (q--) {
		int l, r; cin >> l >> r;
		int len = r-- - l-- + 1;
		if (len & 1) cout << "1\n";
		else {
			l = (r + l)/2, r = l + 1;
			cout << a[r] - a[l] + 1 << '\n';
		}
	}
}