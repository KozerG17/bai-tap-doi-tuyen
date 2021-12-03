/**
 *    author:  Dao Le Bao Minh
 *    created: 01.12.2021 08:21:42  
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
namespace {
	using ll = long long;
	mt19937_64 Rng(chrono::steady_clock::now().time_since_epoch().count());
	static const ll FIXED_RANDOM = Rng();
	ll Rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(Rng); }
} // random number generators
struct custom_hash {
	static uint64_t _splitmix64_(uint64_t x) {
		x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const { return _splitmix64_(x + FIXED_RANDOM); }
}; // custom_hash

const int N = 5e5;

int n, a[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("pearl.INP", "r", stdin);
	// freopen("pearl.OUT", "w", stdout);
	
	cin >> n;
	For (i, 0, n) cin >> a[i];

	deque<int> dq;
	Rof (i, sqrt(n) + 1, 1)
		if (n % i == 0) {
			dq.push_front(i);
			if (i*i != n)
				dq.push_back(n/i);
		}

	cout << dq.size() << '\n';
	for (int i : dq) {
		int ans = n, cnt = i;
		unordered_set<int, custom_hash> st;
		for (int j = 0; j < n; j++)
			if (st.insert(a[j]); --cnt == 0) {
				ans = min(ans, (int)st.size());
				st.clear(); cnt = i;
			}
		cout << i << ' ' << ans << '\n';
	}
}