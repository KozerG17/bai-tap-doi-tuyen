#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;
namespace {
	// macros definitions
	#define Gint Read<ll>()
	#define Gstr Read<str>()
	#define all(a)  (a).begin(),  (a).end()
	#define rall(a) (a).rbegin(), (a).rend()
	#define For(i, u, v) for (int i = (u), _n_ = (v); i < _n_; i++)
	#define Rof(i, u, v) for (int i = (u), _n_ = (v); --i >= _n_; )

	// typedefs & constants
	using chr = char;     using ll = long long;     using pll = pair<ll, ll>;
	using str = string;   using ld = long double;   using pii = pair<int, int>;
	template<class T> using MaxHeap = priority_queue<T, vector<T>,    less<T>>;
	template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
	const ld eps = 1000000 * 0.0000000000001, pi = 3.1415926535897932384626433;
	const ll mod = 1e9 + 7, lim = 1e6 + 1411, e30 = 1ll << 30, e60 = 1ll << 60;

	// useful functions
	template<class A, class B>
	bool Maxz(A &a, B b) { return a < b && (a = b, true); }
	template<class A, class B>
	bool Minz(A &a, B b) { return b < a && (a = b, true); }
	template<class T> T Read() { T x; return cin >> x, x; }
	int hextoint(char c) { return 9 * (c >> 6) + c & 017; }
	int isvowel(char c) { return 2130466 >> (c & 31) & 1; }
} // main template



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const short luv = 17 * 83;
const int N = 1e5 + 5;

ll n, l, r, a[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n >> l >> r;

	ll llen, rlen;
	llen = rlen = e30;

	For (i, 0, n) {
		cin >> a[i];
		Minz(llen, abs(l - a[i]));
		Minz(rlen, abs(r - a[i]));
	}

	ll x, xlen = 0;
	auto upd = [&](int y, int ylen) {
		if (ylen < xlen) return;
		if (ylen > xlen || y > x)
			x = y, xlen = ylen;
	}; upd(l, llen); upd(r, rlen);

	For (i, 1, n) {
		ll y = (a[i-1]+a[i])/2;
		if (y < l) continue;
		if (y > r) continue;
		upd(y, y - a[i-1]);
	}

	cout << x << '\n';
}

// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 03.01.2022 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------