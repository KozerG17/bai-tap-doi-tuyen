/**
 *    author:  Dao Le Bao Minh
 *    created: 28.10.2021 07:31:20  
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

ll n, k, a[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("medianmax.INP", "r", stdin);
	// freopen("medianmax.OUT", "w", stdout);
	
	cin >> n >> k;
	For (i, 0, n) cin >> a[i];
	sort(a, a + n);

	ll med = a[(n-1)/2], cnt = 1;
	For (i, (n+1)/2, n) {
		if (k < (a[i] - med)*cnt) break;
		k -= (a[i] - med)*cnt++; med = a[i];
	}

	cout << med + k/cnt;
}