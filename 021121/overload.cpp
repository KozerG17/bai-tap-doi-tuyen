/**
 *    author:  Dao Le Bao Minh
 *    created: 02.11.2021 08:38:46  
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

int n, m, a[N], b[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("overload.INP", "r", stdin);
	freopen("overload.OUT", "w", stdout);
	
	cin >> n >> m;
	For (i, 0, n) cin >> a[i];
	For (i, 0, m) cin >> b[i];

	set<pii> s;
	For (i, 0, n) s.emplace(a[i], i);
	memset(a, -1, sizeof a);
	For (i, 0, m) {
		auto itr = s.upper_bound(pair(b[i], n));
		if (itr-- == s.begin()) continue;
		a[itr -> se] = i + 1; s.erase(itr);
	}
	For (i, 0, n) cout << a[i] << '\n';
}