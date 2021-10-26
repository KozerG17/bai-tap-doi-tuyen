/**
 *    author:  Dao Le Bao Minh
 *    created: 26.10.2021 08:05:31  
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
const int N = 1e5 + 5;

ll n, k, l, a[N];
bool check(ll m) {
	ll sum = 0;
	For (i, 0, m) {
		if (a[i] >= m) continue;
		if (m - a[i] > k) return false;
		sum += m - a[i];
	}
	return sum <= k*l;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("stronglib2.INP", "r", stdin);
	freopen("stronglib2.OUT", "w", stdout);
	
	cin >> n >> k >> l;
	For (i, 0, n) cin >> a[i];
	sort(a, a + n, greater<ll>());

	ll low = 0, high = n;
	while (low <= high) {
		ll mid = (low + high)/2;
		if (check(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << high;
}