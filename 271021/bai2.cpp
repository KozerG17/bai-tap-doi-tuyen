/**
 *    author:  Dao Le Bao Minh
 *    created: 27.10.2021 08:48:23  
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
const int N = 21;

ll n, k, p[N];
ll index;

ll a[N], b, c[N], cnt = 0;
void quaylui(int pos, int crr) {
	if (pos == k + 1) {
		bool ok = true; cnt++;
		For (i, 1, k + 1) {
			ok &= c[i] == p[i];
		}
		if (ok) b = cnt;
		if (cnt == index) {
			For (i, 1, k + 1)
				a[i] = c[i];
		}
		return;
	}

	For (val, crr, pos + n - k + 1) {
		c[pos] = val;
		quaylui(pos + 1, val + 1);
	}
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n >> k;
	For (i, 1, k + 1) cin >> p[i];
	cin >> index;

	quaylui(1, 1); cout << b << '\n';
	For (i, 1, k + 1) cout << a[i] << ' ';
}